#include <stdio.h>
#include <math.h>

#define N 3 


int main() {
    double A[N][N + N] = {
        {2,-1,0,1,0,0},
        {-1,2,-1,0,1,0},
        {0,-1,2,0,0,1},
        
    };
    double X[N], temp, m, sum, dia, d;
    int i, j, k, M;
    M = N+N;
    
    for (i = 0; i < N-1 ; i++) {
                     
        for (j = i + 1; j < N; j++) {
            m = A[j][i] / A[i][i];
            for (k = i; k <M; k++) {
                A[j][k] -= m * A[i][k];
            }
        }
   
    }
   
    for(i=N-1; i>0; i--){
    	for(j=i-1; j>=0; j--){
    	   m = A[j][i]/A[i][i];
    	   for (k = i; k <M; k++) {
                A[j][k] -= m * A[i][k];
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
}