/*#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define f(x) (((x)*(x))+1)
int main(void){
    int i, n=10;
    double A,B, h;
    double fw, fc, fb;
    A=0.0;
    B=2.0;
    h=(B-A)/n;
    double x[11], y[11];
    x[0]=A;
    for(i=1; i<n; i++){
    	x[i] = x[i-1]+h;
    }
    x[n]=B;
    for(i=0; i<=n; i++) {
      y[i] = f(x[i]);
    }
    
    fw = ((y[1]-y[0])/(x[1]-x[0]));
    printf("%lf\n", fw);
    for(int k=1; k<n; k++){
       fc = ((y[k+1]-y[k-1])/(x[k+1]-x[k-1]));
       printf("%lf\n", fc);
    }
    fb = ((y[n]-y[n-1])/(x[n]-x[n-1]));
    printf("%lf\n", fb);
    
return 0;
}*/

//by meeeeeeeeeeeeeeeeeeeeeeeeeee
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define f(x) ((x)*(x)+1)
//#define f(x) ((x)*(sin(x)))
#define N n
int main(void){
    int i, n=10;
    double a = 0.0, b = 2.0, h, x[n+1], fc, ff, fb;
    h = (a+b)/n;
    x[0] = a; x[n] =b;
    for(i=1; i<n; i++){
        x[i] = x[i-1]+h;
    }
    ff = (f(x[1]) - f(x[0]))/h;
    printf("df[0] = %lf\n", ff);
    for(i=1; i<n; i++){
        fc = (f(x[i+1]) - f(x[i-1]))/(2*h);
        printf("df[%d] = %lf\n", i, fc);
    }
    fb = (f(x[i]) - f(x[i-1]))/h;
    printf("df[10] = %lf\n",fb);
    return 0;
}
