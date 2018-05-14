#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

//funcion que controla el avanse
float Udtmasuno(float Ueni,float vel,float dt, float dx, float Uimenos, float Uenimasu,float Un);

float Udtmasuno(float Ueni , float vel,float dt, float dx, float Uimenos, float Uenimasu, float Un)
{
  float U;
  U= ((vel*dt*dt)/(dx*dx)) * (Uenimasu- 2.0*Ueni + Uimenos) + 2.0*Ueni-Un;
  return U;
}

//funcion descrita por condiciones iniciales
float fx(float x,float L);
float fx(float x,float L)
{ 
if(x<=(0.8*L))
{
  return(1.25*x/L);
}

else
{
  return(5.0-(5*x/L));
} 

}

int main(){

  float L=100.0;

  float vel;
  vel=2.0;

  float tiempo;
  tiempo=200.0;

  float dx; 
  dx=0.1;

  float posicion; 
  posicion=0.0;

  float dt;
  dt=0.001;

  int pasost;
  pasost = (tiempo/dt)+1; 
  
  int pasosx;
  pasosx = (L/dx)+1; 


  float* lista = NULL;
  lista = new float[pasosx];
  
  float* lista1 = NULL;
  lista1 = new float[pasosx];
  
  float* lista2 = NULL;
  lista2 = new float[pasosx];
  
  

//condiciones inicniales
 for(int i=0;i <(pasosx) ;i++)
{
 lista[i]=fx(dx*i,L);
 lista1[i]=fx(dx*i,L);
}

//condiciones de frontera
lista[0]=0.0;
lista2[0]=0.0;
lista1[0]=0.0;


// cambia los valores guardados en la lista
for(int t=0; t<pasost; t++)
{
for(int i=1; i<(pasosx);i++)
{
    posicion = i*dt;
    lista2[i]= Udtmasuno(lista1[i], vel, dt, dx,lista1[(i-1)],lista1[(i+1)], lista[(i)]);
    if(t%10000==0)
{ 
    cout<< " "<<lista2[i]<<" ";
    if(i==(pasosx-1))
{
    cout << endl;
}
}
}

for(int i=0; i<pasosx;i++)
{
    lista[i]=lista1[i];
    lista1[i]=lista2[i];
    
}

}

  return 0;
}

