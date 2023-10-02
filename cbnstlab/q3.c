#include <stdio.h>
#include <math.h>

// Define the function you want to solve for
double f(double x) {
    // Modify this function for your specific equation
    return x * x * x - 5.0 * x + 1.0;
}

// Secant method to find the root of the equation f(x) = 0
double secantMethod(double x0, double x1, double tolerance) {
    double x2, f0, f1, f2;

    int iteration = 0;

    printf("\nIteration\t x0\t\t f(x0)\t\t x1\t\t f(x1)\t\t x2\t\t f(x2)\n");

    do {
        f0 = f(x0);
        f1 = f(x1);

        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        f2 = f(x2);

        printf("%d\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\t\t%.3lf\n", iteration, x0, f0, x1, f1, x2, f2);

        if (fabs(f2) < tolerance || fabs(x2 - x1) < tolerance || iteration >= 20) {
            if (iteration >= 20) {
                printf("Not convergent after %d iterations.\n", iteration);
                return NAN; // Not-a-Number to indicate failure
            }
            return x2;
        }

        x0 = x1;
        x1 = x2;
        iteration++;
    } while (1);
}

int main() {
    double x0, x1, tolerance, root;

    printf("Enter the initial guess (x0): ");
    scanf("%lf", &x0);

    printf("Enter another initial guess (x1): ");
    scanf("%lf", &x1);

    printf("Enter the tolerance (e.g., 0.001 for three decimal places): ");
    scanf("%lf", &tolerance);

    root = secantMethod(x0, x1, tolerance);

    if (!isnan(root)) {
        printf("\nApproximate root correct up to three decimal places: %.3lf\n", root);
    }

    return 0;
}
