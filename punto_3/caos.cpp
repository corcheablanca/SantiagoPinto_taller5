#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
using namespace std;


//se declaran las funciones.
float fp1(float p1, float p2, float q1, float q2);

float fp1(float p1, float p2, float q1, float q2)
{
  return((-2.0*q1)/pow( ((4.0*q1*q1)+(1.0/1000000.0)),1.5) );
}

float fp2(float p1, float p2, float q1, float q2);

float fp2(float p1, float p2, float q1, float q2)
{
   return(((q1-q2)/pow(((4.0*(q1-q2)*(q1-q2))+(1.0/4000000.0)),1.5) )-((q1+q2)/pow(((4.0*(q1+q2)*(q1+q2))+(1.0/4000000.0)),1.5)));
}

float fq1(float p1, float p2, float q1, float q2);

float fq1(float p1, float p2, float q1, float q2)
{
   return(p1);
}

float fq2(float p1, float p2, float q1, float q2);

float fq2(float p1, float p2, float q1, float q2)
{
  return(p2);
}


int main(){

//se declaran las constantes

 float a=1.0/(2.0*sqrt(2.0)); 
 float p1=0.0;
 float p2=0.0;
 float q1=a;
 float q2=-a;
 float q1viejo=a;
 float t=0.0;
 float h=0.006;
 float pasos=3000/h;
 float p11;
 float p21;
 float q11;
 float q21; 
 float p12;
 float p22;
 float q12;
 float q22;
 float p13;
 float p23;
 float q13;
 float q23;
 float p14;
 float p24;
 float q14;
 float q24;

// se corren las iteraciones para encontrar los puntos
 for(int i=0;i<pasos;i++)
{

  p11=fp1(p1,p2,q1,q2); p21=fp2(p1,p2,q1,q2);  q11=fq1(p1,p2,q1,q2); q21=fq1(p1,p2,q1,q2);

  p12=fp1(p1+(h/2.0)*p11,p2+(h/2.0)*p21,q1+(h/2.0)*q11,q2+(h/2.0)*q21);
  p22=fp2(p1+(h/2.0)*p11,p2+(h/2.0)*p21,q1+(h/2.0)*q11,q2+(h/2.0)*q21);
  q12=fq1(p1+(h/2.0)*p11,p2+(h/2.0)*p21,q1+(h/2.0)*q11,q2+(h/2.0)*q21);
  q22=fq1(p1+(h/2.0)*p11,p2+(h/2.0)*p21,q1+(h/2.0)*q11,q2+(h/2.0)*q21);
  p13=fp1(p1+(h/2.0)*p12,p2+(h/2.0)*p22,q1+(h/2.0)*q12,q2+(h/2.0)*q22);
  p23=fp2(p1+(h/2.0)*p12,p2+(h/2.0)*p22,q1+(h/2.0)*q12,q2+(h/2.0)*q22);
  q13=fq1(p1+(h/2.0)*p12,p2+(h/2.0)*p22,q1+(h/2.0)*q12,q2+(h/2.0)*q22);
  q23=fq1(p1+(h/2.0)*p12,p2+(h/2.0)*p22,q1+(h/2.0)*q12,q2+(h/2.0)*q22);

  p14=fp1(p1+h*p13,p2+h*p23,q1+h*q13,q2+h*q23); p24=fp2(p1+h*p13,p2+h*p23,q1+h*q13,q2+h*q23);
  q14=fq1(p1+h*p13,p2+h*p23,q1+h*q13,q2+h*q23); q24=fq1(p1+h*p13,p2+h*p23,q1+h*q13,q2+h*q23);  

  p1=p1+(h/6.0)*(p11+2*p12+2*p13+p14);p2=p2+(h/6.0)*(p21+2*p22+2*p23+p24);q1=q1+(h/6.0)*(q11+2*q12+2*q13+q14);q2=q2+(h/6.0)*(q21+2*q22+2*q23+q24);  
  
// se actualizan si cambia el signo
if((q1*q1viejo<0.0))
{
cout<<q2<<" "<<p2<<endl;
}
  q1viejo=q1;  
}
return(0);
} 
 
