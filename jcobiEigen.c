#include <stdio.h>
#include <math.h>

#define N 2 // Size of the matrix

void jacobiEigenvalue(double A[N][N], double V[N][N], double D[N]) {
    int i, j, p, q, k;
    double t, c, s;

    // Initialize V as the identity matrix
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            V[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    // Initialize D as the diagonal of A
    for (i = 0; i < N; i++) {
        D[i] = A[i][i];
    }

    // Number of iterations (adjust as needed)
    int max_iter = 100;
    int iter = 0;

    // Tolerance for convergence
    double tol = 1e-10;

    do {
        // Find the indices (p, q) of the off-diagonal element with the largest absolute value
        p = 0;
        q = 1;
        for (i = 0; i < N; i++) {
            for (j = i + 1; j < N; j++) {
                if (fabs(A[i][j]) > fabs(A[p][q])) {
                    p = i;
                    q = j;
                }
            }
        }

        // Compute the Jacobi rotation matrix
        if (fabs(A[p][q]) > tol) {
            double app = A[p][p];
            double aqq = A[q][q];
            double apq = A[p][q];

            t = apq / (aqq - app);
            c = 1.0 / sqrt(1.0 + t * t);
            s = c * t;

            // Update the diagonal and off-diagonal elements of A
            A[p][p] = app * c * c + aqq * s * s - 2.0 * apq * c * s;
            A[q][q] = app * s * s + aqq * c * c + 2.0 * apq * c * s;
            A[p][q] = 0.0;
            A[q][p] = 0.0;

            // Update the columns of V
            for (k = 0; k < N; k++) {
                double vp = V[k][p];
                double vq = V[k][q];
                V[k][p] = vp * c - vq * s;
                V[k][q] = vp * s + vq * c;
            }
        }

        iter++;
    } while (iter < max_iter);

    // Store the eigenvalues in D
    for (i = 0; i < N; i++) {
        D[i] = A[i][i];
    }
}

int main() {
    double A[N][N] = {{17.0, 32.0},
                      {32.0, 65.0}};

    double V[N][N];
    double D[N];

    jacobiEigenvalue(A, V, D);

    // Print the eigenvalues
    printf("Eigenvalues:\n");
    for (int i = 0; i < N; i++) {
        printf("%f\n", D[i]);
    }

    // Print the eigenvectors (columns of V)
    printf("\nEigenvectors:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%f ", V[j][i]);
        }
        printf("\n");
    }

    return 0;
}
