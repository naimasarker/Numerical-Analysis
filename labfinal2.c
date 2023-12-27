#include <stdio.h>
#include <math.h>

#define N 3

void matrixVectorMultiply(double A[N][N], double x[N], double result[N]) {
    for (int i = 0; i < N; i++) {
        result[i] = 0.0;
        for (int j = 0; j < N; j++) {
            result[i] += A[i][j] * x[j];
        }
    }
}

double vectorNorm(double x[N]) {
    double norm = 0.0;
    for (int i = 0; i < N; i++) {
        norm += x[i] * x[i];
    }
    return sqrt(norm);
}

void normalizeVector(double x[N]) {
    double norm = vectorNorm(x);
    for (int i = 0; i < N; i++) {
        x[i] /= norm;
    }
}

int main() {
    double A[N][N] = {{2, -1, 0}, {-1, 2, -1}, {0, -1, 2}};
    double x[N] = {1, 0, 0};
    double x_prev[N];
    double lambda, lambda_prev;

    double epsilon = 1e-6; 

    /*printf("- - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("Iter | ( x_1 x_2 x_3 )^T | Lambda\n");
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - -\n");*/

    int iteration = 0;
    do {
        
        lambda_prev = lambda;
        matrixVectorMultiply(A, x, x_prev);
        lambda = vectorNorm(x_prev);
        //printf("%2d | %.6lf %.6lf %.6lf |", iteration, x[0], x[1], x[2]);
       /*if (iteration > 0) {
            printf(" %.6lf", lambda_prev);
        }*/
        //printf("\n");
        normalizeVector(x_prev);
        for (int i = 0; i < N; i++) {
            x[i] = x_prev[i];
        }
        iteration++;
    } while (fabs(lambda - lambda_prev) >= epsilon && iteration < 1000);

    //printf("- - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("Approximate eigenvalue = %.6lf\n", lambda);
    //printf("Corresponding eigenvector = ( %.6lf, %.6lf, %.6lf )^T\n", x[0], x[1], x[2]);

    return 0;
}
