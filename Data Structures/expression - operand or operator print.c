/* Q) Write a program that inputs an expression as a string and displays the operands as numbers ( by using printf("%d") ) and operators as
characters ( by using printf("%c") or putchar() ) on separate lines.
Example :
Input expression : 4+7*2-3
Output : Operand : 4
Operator : +
Operand : 7
Operator : *
Operand : 2
Operator : -
Operand : 3
Note : Consider only the operators : + - * / % ( )
Test your program with different expressions using brackets or without brackets.*/





#include<stdio.h>;

int main()
    {
    char inp[100];
    printf("Enter the expression\n");
    gets(inp);
    int len,i;
    len = strlen(inp);
    for(i=0;i<len;i++)
    {
    if(isdigit(inp[i])!=0)
    printf("Operand = %c\n", inp[i]);
    else
    printf("Operator = %c\n", inp[i]);
    }
    getch();
    return 0;
    }
