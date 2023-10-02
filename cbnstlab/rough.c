#include <stdio.h>
#include <math.h>
//if f(x0)*f(x2)<0 then x1=x2
//else if f(x2)*f(x1)<0 then x0=x2
double func(double x) {
    return x*x - 4*x - 9;
}
double bisection(double a, double b, double epsilon) {
    double c;
    int iteration = 0;
    printf("Iteration\tApproximation\n");
    while ((b - a) >= epsilon) {
        c = (a + b) / 2;
        printf("%d\t\t%.8lf\n", iteration, c);
        if (func(c) == 0.0) {
            return c;
        }
        else if (func(c) * func(a) < 0) {
            b = c;
        }
        else {
            a = c;
        }
        iteration++;
    }
    return c;
}
int main() {
    double a, b, epsilon, root;
    int decimalPlaces;
    printf("Enter the first approximation: ");
    scanf("%lf", &a);
    printf("Enter the second approximation: ");
    scanf("%lf", &b);
    printf("Enter the number of decimal places for answer check: ");
    scanf("%d", &decimalPlaces);
    epsilon = pow(10, -decimalPlaces);
    root = bisection(a, b, epsilon);   
    printf("\nFinal root: %.3lf\n", root);
    return 0;
}