#include<stdio.h>
#include"stack_char.c"

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
            while(peek()!='(')
                    out[pos_of_out++] = pop();
            pop();
        }
        else
        {
            if(inp[i]=='(')
               push(inp[i]);
            else
            {
            while(operator(inp[i]) < operator(peek()))
                out[pos_of_out++] = pop();
            push(inp[i]);
            }
        }
    }
    }
    while(!isempty())
        out[pos_of_out++] = pop();
    out[pos_of_out] = '\0';
    printf("Postfix:\n");
    puts(out);
    getch();
    return 0;
    }
