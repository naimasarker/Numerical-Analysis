#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define EPS 10.0e-6
#define f(x) ((x)*(x)*(x)+4*(x)*(x)-10)
//#define f(x) ((x)*(x)*(x)*(x) - 11*(x) + 8)
int main(void){
    int n = 100, i;
    //double a=1.25, b=1.5, c;
	double a=1, b=2, c;
    if(f(a)*f(b)>0) exit(0);
    printf("----------------------------------------------------------------------\n");
    printf("Iter  	 a  	  b  	  c  	 f(a)      f(b)     f(c)\n");
    printf("--------------------------------------------------------------\n");
    for(i=1; i<n; i++){
    	c = ((a*f(b)-b*f(a))/(f(b)-f(a)));
    	printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf\n",i,a,b,c,f(a),f(b),f(c));
    	if(fabs(f(c))<EPS){
    	  printf("ROOT = %lf\n", c); exit(0);
    	}
    	if(f(a)*f(c)<0){
    	   b=c;
    	}
    	else{
    	    a = c;
    	}
    }
    return 0;
}
