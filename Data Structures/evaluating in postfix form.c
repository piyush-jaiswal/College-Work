/* Q) Write a program that inputs an expression in postfix notation and evaluates its result.
Example :
Input Expression : 472*+3-
Output : 15
Note: Test your program with simple expressions first ( like 53- 43+2- and so on ).  */

#include<stdio.h>
#include"stacks.c"

int main()
    {
    char inp[100];
    int len,i,a,b;
    printf("Enter the expression in postfix form\n");
    gets(inp);
    len=strlen(inp);
    for(i=0;i<len;i++)
    {
    if(isdigit(inp[i])!=0)
    push((int)(inp[i]-48));
    else
    {
    a=pop();
    b=pop();
    if(inp[i]=='+')
    push(b+a);
    else if(inp[i]=='-')
    push(b-a);
    else if(inp[i]=='*')
    push(b*a);
    else if(inp[i]=='/')
    push(b/a);
    }
    }
    printf("Answer = %d\n", pop());
    getch();
    return 0;
}
