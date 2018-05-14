#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

//funcion que controla el avanse
float U(float imasuj,float imenosuj,float ijmenosu, float ijmasu);

float U(float imasuj,float imenosuj,float ijmenosu, float ijmasu)
{
  float U;
  U= (imasuj+imenosuj+ijmenosu+ ijmasu)/4.0;
  return U;
}

//funcion descrita por condiciones iniciales

int main(){

  float L=5.0;

  float l=2.0;

  float d=1.0;

  float h= (5.0/512.0);

  int size = (512);

  float V_0 = 100; 

  int N=2*(L/h)*(L/h);
  
  float V[size][size];

//rellenar la matriz con la scondiciones iniciales y de frontera
for (int i=0;i< size;i++)
{
for (int j=0;j< size;j++)
{
//rayita superior
if( ( j*h >= 1.5) and ( j*h <= 3.5) and (i == 205) )
{ 
V[i][j] = V_0/2.0;  
}
//rayita inferior	
else if( ( j*h >= 1.5 ) and ( j*h <= 3.5 ) and (i == 307) )
{ 
V[i][j] = -V_0/2.0;
}	
//relleno	
else if( (j*h >= 1.5 ) and ( j*h <= 3.5 )  and (i > 205) and (i< 307 ) )
{ 
V[i][j] = V_0;
}
// todo lo demas
else
{ 
V[i][j] = 0.0; 
}
}	
}


for (int i=0;i< size;i++)
{
for (int j=0;j< size;j++)
{  
cout<<V[i][j];
}
cout<<endl;
}
/**
// cambia los valores guardados en la lista
for(int t=0; t<; t++)
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

}**/

  return 0;
}
