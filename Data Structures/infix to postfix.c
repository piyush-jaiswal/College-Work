/* Q)  Write a program to input an infix expression as a string. The program should generate a postfix string of this expression.
The resulting postfix string should be applied to the postfix evaluating program that you have written earlier to get a computed value.
Verify this value with manual mathematical process.

Only consider the following operators : / * + -  and consider the use of brackets as well.
Test your program with embedded brackets and a mix of various kind of operators.

Your program needs to have priority of every operator in the order of high to low for   / * + -
So / has the highest priority and - has the lowest priority. No two operators are to be considered to have same priority as indicated by some resources
on the internet.

Note: Do your program in phases. First make a program with very simple same operator expressions. Make it work, and then enhance it
for multiple operators and then implement brackets into it. ( making sure that it is running at every stage before you move to the next level ). */



#include<stdio.h>
#include"postval.c"

int operator(char c)
    {
    if(c=='-')
    return 1;
    else if(c=='+')
    return 2;
    else if(c=='*')
    return 3;
    else if(c=='/')
    return 4;
    else if(c=='(')
    return -1;
    }

int main()
    {
    char inp[100], out[100];
    int i, pos_of_out=0;
    printf("Enter the expression\n");
    gets(inp);
    for(i=0; inp[i]!='\0'; i++)
    {
    if(isdigit(inp[i]))
        push(inp[i]);
    else
    {
        if(inp[i]==')')
        {
            while((char)peek()!='(')
                    out[pos_of_out++] = (char)pop();
            pop(); // removing the opening bracket
        }
        else
        {
            if(inp[i]=='(')
               push(inp[i]);
            else
            {
            while(operator(inp[i]) < operator((char)peek()))
                out[pos_of_out++] = (char)pop();
            push(inp[i]);
            }
        }
    }
    }
    while(!isempty())
        out[pos_of_out++] = (char)pop();
    out[pos_of_out] = '\0';
    printf("Postfix:\n");
    puts(out);
    postval(out);
    getch();
    return 0;
    }

