#include<stdio.h>
#include"stacks.c"

int postval(char *p)
    {
    int len,i,a,b,j;
    char dummy[20];
    len=strlen(p);
    for(i=0;i<len;i++)
    {
    if(isdigit(p[i])!=0)
    {
        j=0;
        while(p[i]!=' ')
        {
            dummy[j++] = p[i];
            i++;
        }
        dummy[j] = '\0';
    push(atoi(dummy));
    }
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
