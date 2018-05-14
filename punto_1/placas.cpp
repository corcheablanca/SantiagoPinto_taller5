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
  float Vnuevo[size][size];
 /** float X[size][size-1];
  float Y[size-1][size];**/

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


// cambia los valores guardados en la lista
for(int t=0; t<100; t++)
{

for(int i=1; i<(size-1); i++)
{
for(int j=1; j<(size-1);j++)
{

 if( (j*h > 3.5 ) or ( j*h < 1.5 )  or (i < 205) or (i> 307 ) )
{ 
V[i][j] =Vnuevo[i][j]= U(V[i+1][j],V[i-1][j],V[i][j-1], V[i][j+1]);
}
   
}
}

for(int i=0; i<size; i++)
{
for(int j=0; j<(size);j++)
{
  V[i][j]=Vnuevo[i][j];  
}
}
    
}
//imprimir

for (int i=0;i< size;i++)
{
for (int j=0;j< size;j++)
{  
cout<<V[i][j]<<" ";
}
cout<<endl;
}
//se deriva para encontrar los campos electricos

for (int i=0;i< size;i++)
{
for (int j=0;j< size-1;j++)
{  
cout<<((V[i][j]-V[i][j+1])/(2.0*h))<<" ";
}
cout<<" "<<0;
cout<<endl;
}

for (int i=0;i< size-1;i++)
{
for (int j=0;j< size;j++)
{  
cout<<((V[i][j]-V[i+1][j])/(2.0*h))<<" ";
}
cout<<endl;
}

  return 0;
}
