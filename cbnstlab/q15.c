#include<stdio.h>

float findValueAt(float x)
{
    return 1/(1+x*x);
}
int main()
{
    int n;
    float i,a,b,sum=0,h;
    int position_of_term=1;
 
    printf("Enter Value of a and b\n");
    scanf("%f%f",&a,&b);
    printf("Enter no. of Intervals\n");
    scanf("%d",&n);

    h=(b-a)/n;
    sum = findValueAt(a) +findValueAt(b);
 
    for(i=a+h;i<b;i=i+h)
    {
       if(position_of_term %3 ==0)
         sum = sum + 2*findValueAt(i);
       else
         sum = sum + 3*findValueAt(i); 
       position_of_term++;   
    }
    sum = (3*h)/8 * sum;

    printf("\nValue of The integral  = %f",sum);    
    
}