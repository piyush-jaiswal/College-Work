/* Q) Write a function power(m,n) which returns m raised to power n.
Use the technique of divide and conquer to reduce the number of multiplications. */



#include<stdio.h>

int power(int m, int n)
{
    int x;
    if(n==1)
    return m;
    if(n%2==0)
    {
        x = power(m,n/2);
        return x*x;
    }
    else
    {
    x = power(m,(n-1)/2);
    return m*x*x;
    }
}

int main()
{
    int b,p;
    printf("Enter the base and power\n");
    scanf("%d", &b);
    scanf("%d", &p);
    printf("%d\n", power(b,p));
}
