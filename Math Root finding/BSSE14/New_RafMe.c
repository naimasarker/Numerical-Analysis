#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define EPS 10.0e-6
//#define f(x) ((x)*(x)*(x)+4*(x)*(x)-10)
//#define df(x) (3*(x)*(x)+8*(x))
#define f(x) ((x)*(x)*(x)*(x) - 11*(x) + 8)
#define df(x)(4*(x)*(x)*(x) -11)

int main(void){
    int n = 100, i;
    double x0 = 1.50, x1;
    
    printf("--------------------------------------------------------------\n");
    printf("Iter  	x0        x1         f(x0)       f'(x0)      f(x1) \n");
    printf("--------------------------------------------------------------\n");
    for(i=1; i<n; i++){
    	x1 = x0 - (f(x0)/df(x0));
    	printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf \n",i,x0, x1, f(x0),df(x0),f(x1));
    	if(fabs(f(x1))<EPS){
    	  printf("ROOT = %lf\n", x1); exit(0);
    	}
    	x0=x1;
    }
    return 0;
}
