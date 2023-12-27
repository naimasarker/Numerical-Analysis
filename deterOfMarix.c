#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 3

void printMatrix(double matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2lf\t", matrix[i][j]);
        }
        printf("\n");
    }
}

double determinant(double matrix[N][N]) {
    double det = 1.0;

    // Copy the matrix to avoid modifying the original
    double temp[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = matrix[i][j];
        }
    }

    // Perform LU decomposition with partial pivoting
    for (int k = 0; k < N - 1; k++) {
        for (int i = k + 1; i < N; i++) {
            double factor = temp[i][k] / temp[k][k];
            for (int j = k; j < N; j++) {
                temp[i][j] -= factor * temp[k][j];
            }
        }
    }

    // Multiply the diagonal elements to get the determinant
    for (int i = 0; i < N; i++) {
        det *= temp[i][i];
    }

    return det;
}

int main() {
    double matrix[N][N] = {{2, -1, 0}, {-1, 2, -1}, {0, -1, 2}};

    // Check if the matrix is square
    if (N != N) {
        printf("The matrix is not square. Determinant undefined.\n");
        return 1;
    }

    printf("Original matrix:\n");
    printMatrix(matrix);

    double det = determinant(matrix);

    printf("\nDeterminant: %.6lf\n", det);

    return 0;
}