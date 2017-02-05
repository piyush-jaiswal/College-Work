/* Q)Write recursive function for factorial.*/


#include<stdio.h>
#include<stdlib.h>

int factorial(int x)
{
    if(x==2)
        exit(0);
if(x==0)
return 1;
else
return (x*factorial(x-1));
}

int main()
{
int x;
printf("Enter the no.\n");
scanf("%d", &x);
printf("Factorial = %d", factorial(x));
getch();
return 0;
}
