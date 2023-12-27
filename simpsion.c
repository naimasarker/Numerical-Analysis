#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define f(x) (((x)*(x))+1)
#define N n

int main(void){
    int i, n=10;
    double h, a=0.0, b=2.0, x[n+1], y[n+1],sum_x, sum_E=0.0, sum_O=0.0, I;
    if(n%2 != 0){
        n = n+1;
    }
    h = (b-a)/n;
printf("%lf\n", h);
    x[0] = a, x[n] = b;
    for(i=1; i<n; i++){
        x[i] = x[i-1]+h;
    }
    for(i=0; i<=n; i++){
        y[i] = f(x[i]);
    }
    
    sum_x = y[0] + y[n];
    for(i=1; i<n; i++){
        if(i%2 != 0 ){
            sum_O = sum_O + y[i];
        }
        else{
            sum_E = sum_E + y[i];
        }
    }
    I = (h*(sum_x + (4*sum_O) + (2*sum_E)))/3;
    printf("Intregal value:%lf\n", I);
    return 0;
}

