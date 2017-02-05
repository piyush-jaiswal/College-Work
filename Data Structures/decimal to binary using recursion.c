/* Q) Decial to binary using recursion.*/


#include<stdio.h>

int binary(int n, int bin, int pow)
{
    if(n==0)
    return bin;
    else
    {
    bin = bin+pow*(n%2);
    n/=2;
    return binary(n,bin,pow*10);
    }
}

int main()
{
printf("%d\n", binary(3,0,1));
}
