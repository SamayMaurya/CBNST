#include<stdio.h>
#include<math.h>

//Define the function for the equation 

double f(double x){
    return x*x*x-4.0*x-9.0;

    //return x - exp(-x);


}

//Bisection methid to find the root of the equation
double bisection(double a, double b, double tolereance){
    double c;

    if (f(a)*f(b)>=0)
    {
        printf("Bisection mehtod may not converge\n");
        return -1.0;
    }
    int iteration =0;
    while ((b-a)>=tolereance) // equal to the vale of tol
    {
        c=(a+b)/2.0;

        if (f(c)==0.0)
        {
            return c;

        }
        else if (f(c)*f(a)<0)
        {
            b=c;
        }
        else
        {
            a=c;
        }

        iteration++;
        printf("Iteration %d: [a, b] = [%.6lf, %.6lf]\n", iteration, a, b);


    }
    return c;

}


int main()
{

    double a,b,tolerance,root;

    printf("Enter the left Interval(a)");
    scanf("%lf",&a);

    printf("Enter the right Interval(b)");
    scanf("%lf",&b);

    printf("Enter the  tolerance in 0.001 types");
    scanf("%lf",&tolerance);

    root = bisection(a,b,tolerance);
    if (root!=-1){
        printf("Approx root corret up to three decimal places: %.3lf\n",root);

    }
    else{
        printf("Bisection methhod did not coverage within the given interval.\n");
        
    }

    return 0;
    
}



// Bisection method to find the root of the equation f(x) = 0

/*
double bisection(double a, double b, double tolerance) {
    double c;

    if (f(a) * f(b) >= 0) {
        printf("Bisection method may not converge.\n");
        return -1.0;
    }

    int iteration = 0;

    printf("Iteration\tApproximation\n");

    while ((b - a) >= tolerance) {
        c = (a + b) / 2.0;

        printf("%d\t\t%.8lf\n", iteration, c);

        if (f(c) == 0.0) {
            return c;
        }
        else if (f(c) * f(a) < 0) {
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
    double a, b, tolerance, root;

    printf("Enter the left boundary (a): ");
    scanf("%lf", &a);

    printf("Enter the right boundary (b): ");
    scanf("%lf", &b);

    printf("Enter the tolerance (e.g., 0.001 for three decimal places): ");
    scanf("%lf", &tolerance);

    root = bisection(a, b, tolerance);

    if (root != -1.0) {
        printf("\nApproximate root correct up to three decimal places: %.3lf\n", root);
    } else {
        printf("Bisection method did not converge within the given interval.\n");
    }

    return 0;
}
*/