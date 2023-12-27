#include<stdio.h>
#include<math.h>
#define f(x) (((x)*(x))+1)
int main(void){
    int i, n=10;
    double A,B, h;
    A=0.0;
    B=2.0;
    h=(B-A)/10;
    double x[11], y[11];
    x[0]=A;
    for(i=1; i<n; i++){
    	x[i] = x[i-1]+h;
    }
    x[n]=B;
    for(i=0; i<=n; i++) {
    y[i] = f(x[i]);
    }
    double sum_x, sum_I=0, I;
    sum_x = y[0]+y[n];
    
    for(int i=1; i<=n-1; i++){
       sum_I = sum_I + y[i];
    }
    
    I = (h*(sum_x + (2 * sum_I)))/2;
    
    printf("Integral value: %lf\n", I);
    
return 0;
}
