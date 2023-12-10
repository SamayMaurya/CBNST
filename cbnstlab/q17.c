#include <stdio.h>
#include <math.h>
double f(double x, double y)
{
    return x + y;
}
int main()
{
    double x0, y0, k1, k2, k3, k4, k, h, xn, yn;
    int n;
    printf("Enter value of x0:");
    scanf("%lf", &x0);
    printf("\nEnter value of y0:");
    scanf("%lf", &y0);
    printf("\nEnter value of calculation point xn:");
    scanf("%lf", &xn);
    printf("\nEnter value of h:");
    scanf("%lf", &h);
    n = (xn - x0) / h;
    for (int i = 0; i < n; i++)
    {
        k1 = h * (f(x0, y0));
        k2 = h * (f((x0 + h / 2), (y0 + k1 / 2)));
        k3 = h * (f((x0 + h / 2), (y0 + k2 / 2)));
        k4 = h * (f((x0 + h), (y0 + k3)));
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        yn = y0 + k;
        printf("x0=%lf\ty0=%lf\tyn=%lf\n", x0, y0, yn);
        x0 = x0 + h;
        y0 = yn;
    }
    printf("\nValue of y at x= %lf is %lf", xn, yn);
}
