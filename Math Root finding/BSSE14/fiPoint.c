#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define EPS 10.0e-6
#define f(x) ((x)*(x)*(x)+4*(x)*(x)-10)
#define g(x) sqrt((10 - ((x)*(x)*(x)))/(4))
int main(void){
    int n = 100, i;
    double x1;
    double x0=1.25;
    printf("----------------------------------------------------------------------\n");
    printf("Iter  	 x0  	  x1        g(x0)     f(x1)   \n");
    printf("--------------------------------------------------------------\n");
    for(i=1; i<n; i++){
    	x1 = g(x0);
    	printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf\n",i,x0, x1, g(x0), f(x1));
    	if(fabs(f(x1))<EPS){
    	  printf("ROOT = %lf\n", x1); exit(0);
    	}
    	else{
    	    x0 = x1;
    	}
    }
    return 0;
}
