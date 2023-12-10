#include <stdio.h>

int main() {
    float x[20], y[20][20], h, fx, fy, u, fact;
    int i, j, n;

    printf("Enter number of data:\n");
    scanf("%d", &n);

    printf("Enter data:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]=", i);
        scanf("%f", &x[i]);
        printf("y[%d]=", i);
        scanf("%f", &y[i][0]);
    }

    // Calculate the forward difference table
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    printf("\nFORWARD DIFFERENCE TABLE\n\n");
    for (i = 0; i < n; i++) {
        printf("%0.2f", x[i]);

        for (j = 0; j <= i; j++) {
            printf("\t%0.3f", y[i - j][j]);
        }

        printf("\n");
    }

    printf("\nEnter the value of x for which you want to find Y: ");
    scanf("%f", &fx);

    h = x[1] - x[0];
    u = (fx - x[0]) / h;
    fy = y[0][0];
    fact = 1;

    // Apply Newton's Forward Difference Interpolation formula
    for (i = 1; i < n; i++) {
        fact *= i;
        fy += (u * y[0][i]) / fact;
        u = u * (u - i);
    }

    printf("\ny(%f)=%.3f\n", fx, fy);

    return 0;
}
