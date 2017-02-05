 /* Q) Write recursive function for finding the GCD ( HCF ) of 2 numbers. */




#include<stdio.h>

int GCD(int a, int b)
{
    if(a==0)
        return b;
    else if(b==0)
        return a;
else if(a>b)
return GCD(a%b,b);
else if(a<b)
return GCD(a, b%a);
}

int main()
{
int a,b;
printf("Enter the nos\n");
scanf("%d", &a);
scanf("%d", &b);
printf("HCF = %d", GCD(a,b));
getch();
return 0;
}
