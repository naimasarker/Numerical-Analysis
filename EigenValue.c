#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to perform matrix-vector multiplication
void matrixVectorMultiply(double A[3][3], double x[3], double result[3]) {
    for (int i = 0; i < 3; i++) {
        result[i] = 0.0;
        for (int j = 0; j < 3; j++) {
            result[i] += A[i][j] * x[j];
        }
    }
}

// Function to normalize a vector
void normalize(double x[3]) {
    double norm = 0.0;
    for (int i = 0; i < 3; i++) {
        norm += x[i] * x[i];
    }
    norm = sqrt(norm);
    for (int i = 0; i < 3; i++) {
        x[i] /= norm;
    }
}

int main() {
    //double A[3][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    double A[3][3] = {{2.0, -1.0, 0.0}, {-1.0, 2.0, -1.0}, {0.0, -1.0, 2.0}};
    double x[3];
    double eigenvalue = 0.0;

    // Initialize x with a random vector
    for (int i = 0; i < 3; i++) {
        x[i] = (double)rand() / RAND_MAX;
        //printf("%d\n", x[i]);
    }

    int maxIterations = 1000;
    double tolerance = 10e-5;

    for (int i = 0; i < maxIterations; i++) {
        double y[3];
        matrixVectorMultiply(A, x, y);

        // Find the largest element of y as an approximation of the eigenvalue
        eigenvalue = y[0];
        for (int j = 1; j < 3; j++) {
            if (fabs(y[j]) > fabs(eigenvalue)) {
                eigenvalue = y[j];
            }
        }

        // Normalize y
        normalize(y);

        // Check for convergence
        double error = 0.0;
        for (int j = 0; j < 3; j++) {
            error += fabs(y[j] - x[j]);
        }
        if (error < tolerance) {
            break;
        }

        // Update x with the normalized y
        for (int j = 0; j < 3; j++) {
            x[j] = y[j];
        }
    }

    printf("Approximate Eigenvalue: %lf\n", eigenvalue);

    printf("Approximate Eigenvector:\n");
    for (int i = 0; i < 3; i++) {
        printf("%lf\n", x[i]);
    }

    return 0;
}