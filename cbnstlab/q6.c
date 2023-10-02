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

    // Gaussian Elimination
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            double factor = A[i][k] / A[k][k];
            for (int j = k; j <= n; j++) {
                A[i][j] -= factor * A[k][j];
            }
        }
    }

    // Back Substitution
    double x[MAX_SIZE];
    x[n - 1] = A[n - 1][n] / A[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < n; j++)     {
            sum += A[i][j] * x[j];
        }
        x[i] = (A[i][n] - sum) / A[i][i];
    }

    // Display the solution

    printf("\nSolution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %.4lf\n", i + 1, x[i]);
    }

    return 0;
}
