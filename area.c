#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define EPS 10.0e-6
#define f(x) sqrt(x)
#define g(x) ((x)*(x))
#define h(x) (g(x)-f(x))
double bisection(){
    int n = 100, i;
    double a=0.5, b=1.5, c;
    if(h(a)*h(b)>0) exit(0);
    
    for(i=1; i<n; i++){
    	c = (a+b)/2;
    	if(fabs(h(c))<EPS){
    	  printf("ROOT = %lf\n", c); return c;
    	}
    	if(h(a)*h(c)<0){
    	   b=c;
    	}
    	else{
    	    a = c;
    	}
    }
    
}

int main(void){
   int i, n=10;
    double A,B, h,sum_x, sum_O=0, sum_E = 0, I;
    if(n%2 != 0){
       n = n+1;
    }
    A=0.0;
    B=bisection();
    h=(B-A)/10;
    double x[11], y[11];
    x[0]=A;
    for(i=1; i<n; i++){
    	x[i] = x[i-1]+h;
    }
    x[n]=B;
    for(i=0; i<=n; i++) {
    y[i] = h(x[i]);
    }
    sum_x = y[0]+y[n];
    
    
    for(i=1; i<=n-1; i++){
       if(i%2 != 0){
          sum_O = sum_O + y[i];
       }
       else{
           sum_E = sum_E + y[i];
       }
       
    }
    
    I = (h*(sum_x + (4 * sum_O)+ (2*sum_E)))/3;
    
    printf("Integral value: %lf\n", fabs(I));
    
return 0;
}

//Area calculate*******Using trapezoidal************************
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define EPS 10.0e-6
#define f(x) sqrt(x)
#define g(x) ((x)*(x))
#define h(x) (f(x)-g(x))

double bisection(){
    double a=0.5, b=1.5, c;
    int i, n=100;
    if(h(a)*h(b)>0){
        return 0;
    }
    for(i=0; i<n; i++){
        c = (a+b)/2;
        if(fabs(h(c))<EPS){
            return c;
        }
        else{
            if(h(a)*h(c)<0){
                b = c;
            }
            else{
                a = b;
            }
        }
    }
}

int main(void){
    int i, n=10;
    double A = 0.0, B, h,x[n+1],y[n+1], sum_x, sum_I=0.0, I;
    B = bisection();
    printf("Root:%lf\n", B);
    h = (B-A)/n;
    x[0] = A;
    x[n] = B;
    for(i=1; i<n; i++){
        x[i] = x[i-1] + h;
    }
    for(i=0; i<n+1; i++){
        y[i] = h(x[i]);
    }
    sum_x = y[0]+y[n];
    for(i=1; i<n; i++){
        sum_I = sum_I+y[i];
    }
    I = (h*(sum_x + 2*(sum_I)))/2;
    printf("Intregal value:%lf\n", I);
    return 0;
}