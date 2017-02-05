#include<stdio.h>
#include"multi dig postval.c"
#include"gettoken.c"

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
    char inp[100], out[100], *dummy;
    int i=0, pos_of_out=0, pos_of_dummy=0;
    printf("Enter the expression\n");
    gets(inp);
    while(inp[i]!='\0')
    {
        dummy = gettoken(inp,i);
        i = i+strlen(dummy);
        if(!isdigit(dummy[0]) && dummy[0]!=' ')
        {
        if(dummy[0]==')')
        {
            while((char)peek()!='(')
                    out[pos_of_out++] = (char)pop();
            pop();
        }
        else
        {
            if(dummy[0]=='(')
               push(dummy[0]);
            else
            {
            while(operator(dummy[0]) <= operator((char)peek()))
                out[pos_of_out++] = (char)pop();
            push(dummy[0]);
            }
        }
    }
    else
    {
        pos_of_dummy = 0;
        while(pos_of_dummy<=(strlen(dummy)-1))
        {
            if(dummy[pos_of_dummy]!=' ')
        out[pos_of_out++] = dummy[pos_of_dummy];
        pos_of_dummy++;
        }
        out[pos_of_out++] = ' ';
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

