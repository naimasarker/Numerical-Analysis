#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define EPS 10.0e-6
#define N 3 

double A[N][N] = {
        {-3,1,1},
        {-1,-8,6},
        {2,3,-11},  
    };
    double b[N][1] = {{-10},{44},{-26}};
    double Di[N][N] = {0};
    int i, j, k,flag = 0;
    double sum =0, x0[N][1] = {0};
    double x1[N][1], Ax[N][1]={0}, delx0[N][1]={0}, bAx[N][1];

void multipication(double Di[N][N]){
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            for(k=0; k<1; k++){
                Ax[i][j] = Ax[i][j] + A[i][k]*x0[k][j]; 
            }
        }
    }
    for(i=0; i<N; i++){
        for(j=0; j<1; j++){
            bAx[i][j] = b[i][j]-Ax[i][j];
        } 
    }
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            for(k=0; k<1; k++){
                delx0[i][j] = delx0[i][j] + Di[i][k]*bAx[k][j];
            }
        }
    }
    for(i=0; i<N; i++){
    	for(j=0; j<1; j++){
    	   printf("%lf ",delx0[i][j]);
    	}
    	printf("\n");
    }
}


int main() {

    for(i=0; i<N; i++){
        Di[i][i] = 1/A[i][i];
    }
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(i != j){
                sum = sum + abs(A[i][j]);
            }
        }
        //printf("%lf\n", sum);
        if(abs(A[i][i]) <= sum){
            flag = 1;
        }
        sum = 0;
        
    }
    if(flag == 1){
        return 0;
    }
    else{
        multipication(Di);
        for(i=0; i<N; i++){
            for(j=0; j<1; j++){
                x1[i][j] = x0[i][j] + delx0[i][j];
            }
        }
    }
    printf("Matrix of X1:\n");
    for(i=0; i<N; i++){
    	for(j=0; j<1; j++){
    	   printf("%.3lf ",x1[i][j]);
    	}
    	printf("\n");
    }
    return 0;
}