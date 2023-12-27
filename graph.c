#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define pi 3.14569
int main(void){
  double a=0.0, b=2*pi, h;
  int n=100, i, j;
  h = (b-a)/n;
  double x[101], y[101];
  x[0] = a;
  for(i=1; i<n; i++) {
    x[i] = x[i-1]+h;
  }
  x[100] = b;
 
  for(i=0; i<=n; i++) {
    y[i] = sin(x[i]);
  }
 
  double f1[101];
  f1[0] = (y[1]-y[0])/(x[1]-x[0]);
 
 
  for(i=1; i<n; i++) {
    f1[i] = (y[i+1]-y[i-1])/(x[i+1]-x[i-1]);
  }
 
  f1[100] = (y[100]-y[99])/(x[100]-x[99]);
 
    printf("   \"x\"   ,  \"y\"   , \"f1(x)\" \n");
    for(int j=0; j<n+1; j++){
    	printf("%lf ,   %lf,      %lf   ", x[j], y[j], f1[j]);
    	printf("\n");
    }
    
return 0;
}
