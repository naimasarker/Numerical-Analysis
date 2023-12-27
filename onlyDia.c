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
    double D[N][N],Ad[N][N];
    double Di[N][N] = {
        {1,0,0},
        {0,1,0},
        {0,0,1},
    };
    
    double B[N][N]={0};
    int i, j, k, M;
    
    for(i=0; i<N; i++){
    	for(j=0; j<N; j++){
    	    if(i==j){
    	       D[i][j] = A[i][j];
    	       Ad[i][j] = 0;
    	    }
    	    else{
    	    	D[i][j] = 0;
    	    	Ad[i][j] = A[i][j];
    	    }
    	}
    }
    
    printf("Matrix D:\n");
    for(i=0; i<N; i++){
    	for(j=0; j<N; j++){
    	   printf("%lf ",D[i][j]);
    	}
    	printf("\n");
    }
    
    printf("Matrix Ad:\n");
    for(i=0; i<N; i++){
    	for(j=0; j<N; j++){
    	   printf("%lf ",Ad[i][j]);
    	}
    	printf("\n");
    }
    
    printf("Inverse of D:\n");
    for(i=0;i<N; i++){
    	Di[i][i] = Di[i][i]/D[i][i];
    }

    for(i=0; i<N; i++){
    	for(j=0; j<N; j++){
    	   printf("%lf ",Di[i][j]);
    	}
    	printf("\n");
    }
    
    for(i=0; i<N; i++){
      for(j=0; j<N; j++){
         B[i][j] = 0;
         for(k=0; k<N; k++){
            B[i][j] = B[i][j] + D[i][k]*Di[k][j]; 
         }
      }
    }   
    
    printf("Matrix D*Di=A:\n");
    for(i=0; i<N; i++){
    	for(j=0; j<N; j++){
    	   printf("%.3lf ",B[i][j]);
    	}
    	printf("\n");
    }
    
    return 0;
}
