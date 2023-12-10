#include <stdio.h>
#include <math.h>
double f(double x, double y)
{
    return x + y;
}
int main()
{
    double x0, y0, xn, h, yn, slope;
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
        slope = f(x0, y0);
        yn = y0 + h * slope;
        printf("x0=%lf\ty0=%lf\tyn=%lf\n", x0, y0, yn);
        y0 = yn;
        x0 = x0 + h;
    }
    printf("\nValue of y at x= %lf is %lf", xn, yn);
}
