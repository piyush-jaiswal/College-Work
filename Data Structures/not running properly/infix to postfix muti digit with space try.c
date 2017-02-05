#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
    }

int muiti_dig(char *operand)
    {
    int o;
    o = atoi(operand);
    return o;
    }

int main()
    {
    char inp[100], dummy[20], op;
    int i, pos_of_multi=0, pos_of_dummy=0, j, pos_of_out=0, f, o, out[100];
    printf("Enter the expression in infix form\n");
    gets(inp);
    for(i=0; inp[i]!='\0'; i++)
    {
    if(inp[i]==' '&&!isdigit(inp[i+1]))
    {
    for(j= pos_of_multi; j<i; j++)
    dummy[pos_of_dummy++] = inp[i];
    dummy[pos_of_dummy++] = '\0';
    o = muiti_dig(dummy);
    out[pos_of_out++] = o;
    pos_of_dummy =0;
    if(isdigit(inp[i+2]))
    pos_of_multi = i+2;
    else
    pos_of_multi = i+3;
    }
    else if(isdigit(inp[i-1])&&inp[i]!=' ')
    {
    for(j= pos_of_multi; j<i; j++)
    dummy[pos_of_dummy++] = inp[i];
    dummy[pos_of_dummy] = '\0';
    o = muiti_dig(dummy);
    out[pos_of_out++] = o;
    pos_of_dummy =0;
    if(isdigit(i+1))
    pos_of_multi = i+1;
    else
    pos_of_multi = i+2;
    op = inp[i];
    f = operator(op);
    if(inp[i]==')')
    {
    while(stackdata[top]!='(')
    out[pos_of_out++] = pop();
    pop();
    }
    else
    {
    if(operator(peek())>f)
    {
    out[pos_of_out++] = pop();
    push (op);
    }
    else
    push (op);
    }
    }
    else
    continue;
    }
    while(top!=-1)
    out[pos_of_out++] = pop();
    out[pos_of_out] = '\0';
    for(j=0; out[j]!='\0'; j++)
        printf("%d", out[j]);
    getch();
    return 0;
    }

