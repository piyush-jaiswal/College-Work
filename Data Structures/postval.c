#include<stdio.h>
#include"stacks.c"

int postval(char *p)
    {
    int len,i,a,b;
    len=strlen(p);
    for(i=0;i<len;i++)
    {
    if(isdigit(p[i])!=0)
    push((int)(p[i]-48));
    else
    {
    a=pop();
    b=pop();
    if(p[i]=='+')
    push(b+a);
    else if(p[i]=='-')
    push(b-a);
    else if(p[i]=='*')
    push(b*a);
    else if(p[i]=='/')
    push(b/a);
    }
    }
    printf("Answer = %d\n", pop());
    getch();
    return 0;
}
