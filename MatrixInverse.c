/*#include<stdio.h>
#include<math.h>
#define N 4
int main(void){
    int i,j,k;
    double temp, x1, x2, x3, x4;
    double a[N][N+1] = {{1,-1,2,-1,-8},{2,-2,3,-3,-20},{1,1,1,0,-2},{1,-1,4,3,4}};
    for(j=0; j<N+1; j++){
    	a[1][j] = a[1][j] - 2*(a[0][j]);
    	a[2][j] = a[2][j] - a[0][j];
    	a[3][j] = a[3][j] - a[0][j];
    }
    for(j=0; j<N+1; j++){
    	temp = a[2][j];
    	a[2][j] = a[1][j];
    	a[1][j] = temp; 
    }
    for(j=0; j<N+1; j++){
        a[3][j] = a[3][j] + 2*(a[2][j]);
    }
    for(i =0; i<N; i++){
      for(j=0; j<N+1; j++){
      	 printf("%7.2lf ", a[i][j]);
      }
      printf("\n");
    }
    
    x4 = (a[3][4])/a[3][3];
    x3 = -(a[2][4]) - x4;
    x2 = (a[1][4] + x3 -x4)/2;
    x1 = a[0][4] + x2 - 2*x3 + x4;
    
    printf("Solutions:\n");
    printf("x1 : %.2lf\n",x1);
    printf("x2 : %.2lf\n",x2);
    printf("x3 : %.2lf\n",x3);
    printf("x4 : %.2lf\n",x4);
    
   
    return 0;
}*/

#include<stdio.h>
#include<math.h>
#define N 4

int main(void){
    double a[N][N+1] = {{1,-1,2,-1,-8},{2,-2,3,-3,-20},{1,1,1,0,-2},{1,-1,4,3,4}};
    //double a[N][N+1] = {{1,0,0,-1,160},{-1,1,0,0,-240},{0,-1,1,0,600},{0,0,-1,1,-520}};
    int i, p, j, k;
    double m, temp, x[N], sum;
    for(i=0; i<N-1; i++){
       p = i;
       while(p<N && a[p][i] == 0){
            p++;
       }
       if(p == N){
          printf("NO unique solution exists.\n");
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
           m = a[j][i] / a[i][i];
           for(k=i; k<=N;  k++){
              a[j][k] -= m*a[i][k];
           }
       }
    }

    if(a[N-1][N-1] == 0){
       printf("NO unique solution exists.\n");
       return 0;
    }

    for(i=0; i<N; i++){
        for(j=0; j<=N; j++){
            printf("%lf ",a[i][j]);
        }
        printf("\n");
    }

    x[N-1] = a[N-1][N] / a[N-1][N-1];

    for(i=N-2; i>=0; i--){
        sum = a[i][N];
        for(j=i+1; j<N; j++){
          sum -= a[i][j] * x[j];
        }
        x[i] = sum / a[i][i];
    }
    printf("Solution:\n");
    for(i=0; i<N; i++){
        printf("x%d = %.3lf\n", i+1, x[i]);
    }
    printf("\n");
    return 0;
}



//Using function
/*#include <stdio.h>

void gaussian_elimination(int n, double A[n][n+1], double x[n]) {
    
    for (int i = 0; i < n - 1; i++) {
        
        int p = i;
        while (p < n && A[p][i] == 0) {
            p++;
        }
        if (p == n) {
            printf("No unique solution exists.\n");
            return;
        }

        if (p != i) {
            
            for (int j = 0; j <= n; j++) {
                double temp = A[p][j];
                A[p][j] = A[i][j];
                A[i][j] = temp;
            }
        }

        
        for (int j = i + 1; j < n; j++) {
            
            double mji = A[j][i] / A[i][i];

            
            for (int k = i; k <= n; k++) {
                A[j][k] -= mji * A[i][k];
            }
        }
    }

    
    if (A[n-1][n-1] == 0) {
        printf("No unique solution exists.\n");
        return;
    }

    
    x[n-1] = A[n-1][n] / A[n-1][n-1];

    
    for (int i = n - 2; i >= 0; i--) {
        double sum = A[i][n];
        for (int j = i + 1; j < n; j++) {
            sum -= A[i][j] * x[j];
        }
        x[i] = sum / A[i][i];
    }

    
    printf("Solution: ");
    for (int i = 0; i < n; i++) {
        printf("x%d = %lf ", i+1, x[i]);
    }
    printf("\n");
}

int main() {
    int n = 4;  
    double A[4][5] = {{1,-1,2,-1,-8},{2,-2,3,-3,-20},{1,1,1,0,-2},{1,-1,4,3,4}};
    double x[n];

    gaussian_elimination(n, A, x);

    return 0;
}*/
