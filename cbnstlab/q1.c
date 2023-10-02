#include<stdio.h>
#include<math.h>
int main()
{
    float true_value, approx_value, truncated_value,
    absolute_error, relative_error, percentage_error,
    t_absolute_error, t_relative_error, t_percentage_error;
    printf("%s","Enter actual value= ");
    scanf("%f",&true_value);
    printf("%s","Enter approx value= ");
    scanf("%f",&approx_value);
    printf("%s","Enter truncated value= ");
    scanf("%f",&truncated_value);
    //absolute error
    absolute_error= fabs(true_value-approx_value);
    printf("Absolute Error= %.2f\n",absolute_error);
    //relative error
    relative_error= absolute_error/true_value;
    printf("Relative Error= %.2f\n",relative_error);
    //percentage error
    percentage_error= relative_error*100;
    printf("Percentage Error= %.2f %%\n",percentage_error);
    //truncated absolute error
    t_absolute_error= fabs(true_value-truncated_value);
    printf("Truncated Absolute Error= %.2f\n",t_absolute_error);
    //truncated relative error
    t_relative_error= t_absolute_error/true_value;
    printf("Truncated Relative Error= %.2f\n",t_relative_error);
    //truncated percentage error
    t_percentage_error= t_relative_error*100;
    printf("Truncated Percentage Error= %.2f %%\n",t_percentage_error);
    return 0;
}