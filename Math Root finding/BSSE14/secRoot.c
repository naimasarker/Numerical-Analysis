#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define EPS 10.0e-6
#define f(x) ((x)*(x)*(x)+4*(x)*(x)-10)
int main(void){
    int n = 100, i;
    double x1=1.25, x2=1.5, x3;
    printf("----------------------------------------------------------------------\n");
    printf("Iter  	 x1  	  x2  	       x3  	  f(x1)    f(x2)     f(x3)\n");
    printf("---------------------------------------------------------------------\n");
    for(i=1; i<n; i++){
    	x3 = ((x1*f(x2)-x2*f(x1))/(f(x2)-f(x1)));
    	printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf\n",i,x1,x2,x3,f(x1),f(x2),f(x3));
    	if(fabs(f(x3))<EPS){
    	  printf("ROOT = %lf\n", x3); exit(0);
    	}
    	else{
    	   x1 = x2;
    	   x2 = x3;
    	}
    }
    return 0;
}
