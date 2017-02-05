#include<stdio.h>
#include"postval.c"

int operator(char c)
    {
    if(c=='-' || c=='+')
    return 1;
    else if(c=='*' || c=='/')
    return 2;
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
        out[pos_of_out++]=inp[i];
    else
    {
        if(inp[i]==')')
        {
            while((char)peek()!='(')
                    out[pos_of_out++] = (char)pop();
            pop(); // removing the opening bracket.
        }
        else
        {
            if(inp[i]=='(')
               push(inp[i]);
            else
            {
            while(operator(inp[i]) <= operator((char)peek()))
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

