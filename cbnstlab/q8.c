#include <stdio.h>
#include <math.h>

#define MAX_SIZE 10
#define MAX_ITER 1000
#define TOLERANCE 0.0001

int main() {
    int n;
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    double A[MAX_SIZE][MAX_SIZE];
    double b[MAX_SIZE];
    double x[MAX_SIZE] = {0};  // Initial guess, often taken as zeros

    printf("Enter the coefficient matrix (A):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Enter the constants vector (b):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }

    int iterations = 0;
    double error;

    do {
        error = 0.0;

        for (int i = 0; i < n; i++) {
            double new_xi = b[i];
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    new_xi -= A[i][j] * x[j];
                }
            }
            new_xi /= A[i][i];

            error += fabs(new_xi - x[i]);
            x[i] = new_xi;
        }

        iterations++;

        if (iterations >= MAX_ITER) {
            printf("Maximum iterations reached.\n");
            break;
        }
    } while (error > TOLERANCE);

    // Display the solution
    printf("\nSolution (converged after %d iterations):\n", iterations);
    for (int i = 0; i < n; i++) {
        printf("x%d = %.4lf\n", i + 1, x[i]);
    }

    return 0;
}
