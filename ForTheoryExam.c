/*#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 10.0e-6
#define f(x) ((x)*(x)*(x)+4*(x)*(x)-10)


int main(void){
    int n = 100, i;
    double a = 1.25, b=1.5, c;
    if(f(a)*f(b)>0) exit(0);
    printf("----------------------------------------------------------------------\n");
    printf("Iter  	 a  	  b  	  c  	 f(a)      f(b)     f(c)\n");
    printf("--------------------------------------------------------------\n");
    for(i=1; i<n; i++){
        c = (a+b)/2;
        printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf\n", i, a, b,c,f(a),f(b),f(c));
        if(fabs(f(c))<EPS){
            printf("\nRoot = %lf\n", c);
            exit(0);
        }
        if(f(a)*f(c)<0){
            b = c;
        }
        else{
            a = c;
        }
        
    }
    return 0;
}*/

/*#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define EPS 10.0e-6
#define f(x) ((x)*(x)*(x)+4*(x)*(x)-10)

int main(void){
    int n=100, i;
    double a=1, b=2, c;
    if(f(a)*f(b)>0) exit(0);
    printf("----------------------------------------------------------------------\n");
    printf("Iter  	 a  	  b  	  c  	 f(a)      f(b)     f(c)\n");
    printf("--------------------------------------------------------------\n");
    for(i=1; i<n; i++){
        c = ((a*f(b)-b*f(a))/(f(b)-f(a)));
        printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf\n",i,a,b,c,f(a),f(b),f(c));
        if(fabs(f(c))<EPS){
            printf("Root = %lf\n", c);
            exit(0);
        }
        if(f(a)*f(c)<0){
            b = c;
        }
        else{
            a = c;
        }
    }
    return 0;
}*/

/*#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 10.0e-6
#define f(x) ((x)*(x)*(x) + 4*(x)*(x)-10)
#define g(x) sqrt((10 - ((x)*(x)*(x)))/(4))

int main(void){
    int n = 100, i;
    double x1;
    double x0 = 1.25;
    printf("----------------------------------------------------------------------\n");
    printf("Iter  	 x0  	  x1        g(x0)     f(x1)   \n");
    printf("--------------------------------------------------------------\n");
    for(i=1; i<n; i++){
        x1 = g(x0);
        printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf\n",i,x0, x1, g(x0), f(x1));
        if(fabs(f(x1))<EPS){
            printf("Root = %lf\n", x1);
            exit(0);
        }
        else{
            x0 = x1;
        }
    }
    return 0;
}*/

//Newton Rafsan methood
/*#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define EPS 10.0e-6
#define f(x) ((x)*(x)*(x)*(x) - 11*(x) + 8)
#define df(x) (4*(x)*(x)*(x) - 11)

int main(void){
    int n =100, i;
    double x0 = 1.50, x1;
    printf("-----------------------------------------------------------------\n");
    printf("Iter\tx0\tx1\tf(x0)\tf'(x0)\tf(x1)\n");
    printf("-------------------------------------------------------------------\n");
    for(i=1; i<n; i++){
        x1 = x0 -(f(x0)/df(x0));
        printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf\n", i, x0, x1,f(x0),df(x0),f(x1));
        if(fabs(f(x1))<EPS){
            printf("Root = %lf\n", x1);
            exit(0);
        }
        x0 = x1;
    }
    return 0;
}*/

/*#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define EPS 10.0e-6
#define f(x) ((x)*(x)*(x)+4*(x)*(x)-10)

int main(void){
    int n = 100, i;
    double x1 = 1.25, x2 = 1.5, x3;
    printf("----------------------------------------------------------------------\n");
    printf("Iter  	 x1  	  x2  	       x3  	  f(x1)    f(x2)     f(x3)\n");
    printf("---------------------------------------------------------------------\n");
    for(i =1; i<n; i++){
        x3 = ((x1*f(x2) - x2*f(x1))/(f(x2)-f(x1)));
        printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf\n",i,x1,x2,x3,f(x1),f(x2),f(x3));
        if(fabs(f(x3))<EPS){
            printf("Root = %lf\n", x3);
            exit(0);
        }
        else{
            x1 = x2;
            x2 = x3;
        }
    }
    return 0;
}*/
// all root
/*#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 10.0e-6
#define f(x) (((x)*(x)*(x))+(4*(x)*(x))-5)

void bisection(double a, double b){
    int i, n =100;
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
            printf("Root: %lf\n", c);
            break;
        }
        if(f(a)*f(c)<0){
            b = c;
        }
        else{
            a = c;
        }
    }
}

int main(void){
    int i;
    double A=-5, B=5, a, b, h;
    h = (B-A)/6;
    a = A;
    for(int i=0; i<6; i++){
        b = a+h;
        bisection(a, b);
        a = b;
    }
    return 0;
}*/
//Numerical differentiation

/*#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N n
#define f(x) ((x)*(x)+1)

int main(void){
    int i, n =10;
    double a =0.0, b=2.0, h, x[n+1], fc, fb, fw;
    h = (a+b)/n;
    x[0] = a;
    x[n] = b;
    for(i=1; i<n; i++){
        x[i] = x[i-1]+h;
    }
    fw = (f(x[1])-f(x[0]))/h;
    printf("df[0]=%lf\n", fw);
    for(i=1; i<n; i++){
        fc = (f(x[i+1])-f(x[i-1]))/(2*h);
        printf("df[%d]=%lf\n", i, fc);
    }
    fb = (f(x[i])-f(x[i-1]))/h;
    printf("df[10]=%lf\n", fb);
    return 0;
}*/

/*#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f(x) (((x)*(x))+1)

int main(void){
    int i, n =10;
    double a, b, h;
    a = 0.0;
    b = 2.0;
    h = (b-a)/10;
    double x[n+1], y[n+1];
    x[0] = a;
    x[n] = b;
    for(i = 1; i<n; i++){
        x[i] = x[i-1]+h;
    }
    for(i=0; i<=n; i++){
        y[i] = f(x[i]);
    }
    double sum_x=0.0, sum_I=0.0, I;
    sum_x = y[0]+y[n];
    for(i=1; i<n; i++){
        sum_I = sum_I+y[i];
    }
    I = (h*(sum_x+(2*sum_I)))/2;
    printf("Integral value:%lf\n", I);
    return 0;
}*/

/*#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f(x) (((x)*(x))+1)
#define N n
int main(void){
    int i, n=10;
    double h, a=0.0, b=2.0, x[n+1], y[n+1],sum_x, sum_E=0.0, sum_O=0.0, I;
    if(n%2 != 0){
        n = n+1;
    }
    printf("%lf\n", h);
    x[0] = a, x[n]=b;
    for(i=1; i<n; i++){
        x[i] = x[i-1]+h;
    }
    for(i=0; i<=n; i++){
        y[i]=f(x[i]);
    }
    sum_x = y[0]+y[n];
    for(i=1; i<n; i++){
        if(i%2 != 0){
            sum_O = sum_O+y[i];
        }
        else{
            sum_E = sum_E+y[i];
        }
    }
    I = (h*(sum_x+(4*sum_O)+(2*sum_E)))/3;
    printf("%lf\n", I);
    return 0;
}*/

//Guessian Elimination
/*#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 4

int main(void){
    double a[N][N+1] = {{1,-1,2,-1,-8},{2,-2,3,-3,-20},{1,1,1,0,-2},{1,-1,4,3,4}};
    int i, p, j, k;
    double m, temp, x[N], sum;
    for(i=0; i<N-1; i++){
        p = i;
        while(p<N && a[p][i] == 0){
            p++;
        }
        if(p == N){
            printf("No unique solution exists.\n");
            return 0;
        }
        if(p != i){
            for(j=0; j<=N; j++){
                temp = a[p][j];
                a[p][j] = a[i][j];
                a[i][j] = temp;
            }
        }
        for(j=i+1; j<N; j++){
            m = a[j][i]/a[i][i];
            for(k=i; k<=N; k++){
                a[j][k] -= m*a[i][k] ;
            }
        }
        
    }
    if(a[N-1][N-1] == 0){
        printf("No unique solution exists.\n");
        return 0;
    }
    x[N-1] = a[N-1][N]/a[N-1][N-1];
    for(i=N-2; i>=0; i--){
        sum = a[i][N];
        for(j=i+1; j<N; j++){
            sum -= a[i][j]*x[j];
        }
        x[i] = sum/a[i][i];
    }
    printf("Solution:\n");
    for(i=0; i<N; i++){
        printf("x%d = %.3lf\n", i+1, x[i]);
    }
    printf("\n");
    return 0;
}*/
//jacobiGuessian 

/*#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 3
double A[N][N] = {
        {4,1,1},
        {2,5,2},
        {1,2 ,4},
    };
double b[N] = {8, 3, 11};
double x[N] = {0};
double xN[N];
int max_iterations =100;
int iteration, i, j, k;
double tolerance = 10e-6;
void jacob(){
    for(iteration =0; iteration<max_iterations; iteration++){
        for(i=0; i<N; i++){
            double sum = b[i];
        
            for(j =0; j<N; j++){
                if(j != i){
                    sum = sum - A[i][j]*x[j];
                }
            }
            xN[i] = sum/A[i][i];
        }
        double max_diff = 0;
        for(i=0; i<N; i++){
            double diff = fabs(xN[i]-x[i]);
            if(diff >max_diff){
                max_diff = diff;
            }
        }
        for(i=0; i<N; i++){
            x[i] = xN[i];
        }
        if(max_diff<tolerance){
            break ;
        }
    }
    printf("Total tolarence:%d\n", iteration);
    printf("Solution:\n");
    for(i=0; i<N; i++){
        printf("x%d = %lf\n", i+1, x[i]);
    }
}
int main(void){
    int flag =0;
    double sum = 0;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(i != j){
                sum = sum + abs(A[i][j]);
            }
        }
        if(abs(A[i][j])<=sum){
            flag ==1;
        }
        sum =0;
    }
    if(flag == 1){
        printf("This matrix is not diagonally dominated.\n");
        return 0;
    }
    else{
        jacob();
    }
    return 0;
}*/
/*#include <stdio.h>
#include <math.h>

#define N 3 
int main(){
    double A[N][N+N] = {
        {4,1,1,1,0,0},
        {2,5,2,0,1,0},
        {1,2,4,0,0,1},
    };
    double X[N], temp, m, sum, dia, d;
    int i, j, k, M;
    M = N+N;
    for(i=0; i<N-1; i++){
        for(j=i+1; j<N; j++){
            m = A[j][i]/A[i][i];
            for(k =i; k<M; k++){
                A[j][k] = A[j][k]- m*A[i][k];
            }
        }
    }
    dia = A[0][0];
    for(i=1; i<N; i++){
        dia = dia *A[i][i];
    }
    printf("Diterminatnt:%lf\n", dia);
    for(i=N-1; i>0; i--){
        for(j=i-1; j>=0; j--){
            m = A[j][i]/A[i][i];
            for(k=i; k<M; k++){
            A[j][k] -= m*A[i][k];
        }
        }
        
    }
    
    for(i=0; i<N; i++){
        d = A[i][i];
        for(j=0; j<M; j++){
            A[i][j] = A[i][j]/d;
        }
    }
    printf("Inverse Matrix of A:\n");
    for(i=0; i<N; i++){
        for(j=3; j<M; j++){
            printf("%.3lf   ", A[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 3
void matrixVectorMultiply(double A[N][N], double x[N], double result[N]){
    for(int i=0; i<N; i++){
        result[i] = 0.0;
        for(int j=0; j<N; j++){
            result[i] += A[i][j]*x[j];
        }
    }
}

double vectorNorm(double x[N]){
    double norm = 0.0;
    for(int i=0; i<N; i++){
        norm += x[i]*x[i];
    }
    return sqrt(norm);
}

void normalizeVector(double x[N]){
    double norm = vectorNorm(x);
    for(int i=0; i<N; i++){
        x[i] /= norm;
    }
}

int main(){
    double A[N][N] = {{2, -1, 0},
                      {-1, 2, -1},
                      {0, -1, 2},
                    };
    double x[N] = {1, 0, 0};
    double xPre[N];
    double lambda, lambda_prev;
    double epsilon = 1e-6;
    int iteration =  0;
    do{
        lambda_prev = lambda;
        matrixVectorMultiply(A, x, xPre);
        lambda = vectorNorm(xPre);
        printf("%2d |%.6lf %.6lf %.6lf|", iteration, x[0], x[1],x[2]);
        printf("\n");
        normalizeVector(xPre);
        for(int i=0; i< N; i++){
            x[i] = xPre[i];
        }
        iteration++;

    }while(fabs(lambda - lambda_prev)>=epsilon && iteration<1000);
    printf("eigen value:=%.6lf\n", lambda);
    printf("Eigen value= %.6lf, %.6lf %.6lf", x[0], x[1], x[2]);
    return 0;
    
}