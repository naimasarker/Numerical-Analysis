#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define EPS 10.0e-6
#define f(x) (((x)*(x)*(x))+(4*(x)*(x))-5)
void bisection(double a, double b){
    int i, n=100;
    double c;
    if(f(a)*f(b)>0){
        return;
    }
    printf("----------------------------------------------------------------------\n");
    printf("Iter  	 a  	  b  	  c  	 f(a)      f(b)     f(c)\n");
    printf("--------------------------------------------------------------\n");
    for(i=1; i<n; i++){
    	c = (a+b)/2;
    	printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf\n",i,a,b,c,f(a),f(b),f(c));
    	if(fabs(f(c))<EPS){
    	  printf("ROOT = %lf\n", c);
          break;
    	}
    	if(f(a)*f(c)<0){
    	   b=c;
    	}
    	else{
    	    a = c;
    	}
    }
}
int main(void){
    int  i;
    double A=-5, B=5,a,b, h;
    h=(B-A)/6;
    a=A;
    for(int i=0;i<6; i++){
        b = a+h;
        bisection(a, b);
        a=b;
    }
    
    return 0;
}