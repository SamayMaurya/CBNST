#include <stdio.h>
#include <math.h>

// function  to solve for
double f(double x) {
    //  function  equation
    //return x * x * x - 3.0 * x - 5.0;
    return x*x-(10);
}

// Derivative of the function
double df(double x) {
    //return 3.0*x*x-3;
    return 2*x;
}

double newtonRaphson(double x0, double tolerance) {
    double x1;

    int iteration = 0;

    while (1) {
        x1 = x0 - f(x0) / df(x0); //using formula

        printf("Iteration %d: x1 = %.4lf, f(x1) = %.4lf\n", iteration, x1, f(x1));

        if (fabs(f(x1)) < tolerance) { //using fab function becs ye absoulte value ke kam aata hai ye math() ka part hai
            return x1;
        }

        x0 = x1;
        iteration++;
    }
}

int main() {
    double x0, tolerance, root;

    printf("Enter the initial guess (x0): ");
    scanf("%lf", &x0);

    printf("Enter the tolerance (e.g., 0.0001 for four decimal places): ");
    scanf("%lf", &tolerance);

    root = newtonRaphson(x0, tolerance);

    printf("\nApproximate root correct up to four decimal places: %.4lf\n", root);

    return 0;
}
