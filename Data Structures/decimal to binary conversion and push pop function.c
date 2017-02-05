/* Q) Write a program ( without using stacks ) that inputs an integer value and finds out the binary equivalent of it.
If the number input was 12, then binary should be printed as 1100

Use stacks by including "stack.c" in this program and see how your solution can be simplified to print the binary digits of the number.*/

#include<stdio.h>;
#include"stacks.c";

int dectobin(int x)
    {
    int bin=0,d,pv=1;
    while(x!=0)
    {
    d=x%2;
    x=x/2;
    bin= bin+d*pv;
    pv = pv*10;
    }
    return bin;
    }

int main()
    {
    push(36);
    push(24);
    push(15);
    int x, xbin;
    x = pop();
    xbin = dectobin(x);
    printf("Popped no. = %d\n", x);
    printf("Popped no. binary equivalent = %d\n", xbin);
    getch();
    return 0;
    }

