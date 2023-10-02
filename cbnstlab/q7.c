#include <stdio.h>

#define MAX_SIZE 10

int main() {
    int n;
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    double A[MAX_SIZE][MAX_SIZE + 1];
    printf("Enter the augmented matrix (coefficients + constants):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    // Gauss-Jordan Elimination
    for (int k = 0; k < n; k++) {
        if (A[k][k] == 0.0) {
            printf("Pivot element is zero. Cannot continue.\n");
            return 1;
        }

        // Make the diagonal element 1
        double pivot = A[k][k];
        for (int j = 0; j <= n; j++) {
            A[k][j] /= pivot;
        }

        for (int i = 0; i < n; i++) {
            if (i != k) {
                double factor = A[i][k];
                for (int j = k; j <= n; j++) {
                    A[i][j] -= factor * A[k][j];
                }
            }
        }
    }

    // Display the solution
    printf("\nSolution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.4lf\n", i + 1, A[i][n]);
    }

    return 0;
}
