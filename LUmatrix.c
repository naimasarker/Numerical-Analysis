#include <stdio.h>
#include <math.h>

#define N 3 


int main() {
    double A[N][N] = {
        {4,1,1},
        {2,5,2},
        {1,2,4},
        
    };
    double X[N], temp, m;
    double U[N][N];
    double L[N][N] = {
         {1,0,0},
         {0,1,0},
         {0,0,1},
    };
    double B[N][N]={0};
    int i, j, k, M;
    
    for(i=0; i<N; i++){
    	for(j=0; j<N; j++){
    	    U[i][j] = A[i][j];
    	}
    }
    
    for (i = 0; i < N-1 ; i++) {
                     
        for (j = i + 1; j < N; j++) {
            m = U[j][i] / U[i][i];
            L[j][i]=m;
            for (k = i; k <N; k++) {
                U[j][k] -= m * U[i][k];
            }
        }
   
    }
    printf("Matrix U:\n");
    for(i=0; i<N; i++){
    	for(j=0; j<N; j++){
    	   printf("%lf ",U[i][j]);
    	}
    	printf("\n");
    }
    
    printf("Matrix L:\n");
    for(i=0; i<N; i++){
    	for(j=0; j<N; j++){
    	   printf("%lf ",L[i][j]);
    	}
    	printf("\n");
    }
    
    for(i=0; i<N; i++){
      for(j=0; j<N; j++){
         B[i][j] = 0;
         for(k=0; k<N; k++){
            B[i][j] = B[i][j] + L[i][k]*U[k][j]; 
         }
      }
    }   
    
    printf("Matrix LU=A:\n");
    for(i=0; i<N; i++){
    	for(j=0; j<N; j++){
    	   printf("%.3lf ",B[i][j]);
    	}
    	printf("\n");
    }
   
    return 0;
}

