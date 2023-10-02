#include<stdio.h>
#include<math.h>

//function defination

double f(double x){
    return x*x*x-5.0*x+1.0;

}

double secant(double a , double b, double tolerance){
    double x0,x1,x2,f0,f1,f2;
    x0 = a;
    x1 = b;

    int iteration = 0;

    while (1) {
        f0 = f(x0);
        f1 = f(x1);

        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        f2 = f(x2);

        printf("Iteration %d: x2 = %.6lf, f(x2) = %.6lf\n", iteration, x2, f2);

        if (fabs(f2) < tolerance || fabs(x2 - x0) < tolerance) {
            return x2;
        }

        if (f0 * f2 < 0) {
            x1 = x2;
        } else {
            x0 = x2;
        }

        iteration++;
    }
}

int main(){
    double a,b,root,tolerance;
    
  printf("Enter the Interval(a): ");
    scanf("%lf", &a);

    printf("Enter the interval(b): ");
    scanf("%lf", &b);


    printf("Enter the tolerance (e.g., 0.001 for three decimal places): ");
    scanf("%lf", &tolerance);
    
    root = secant(a,b,tolerance);

    printf("\nApprox root Corrct up to three decimal Places: %.3lf\n", root);
    
    return 0;


}