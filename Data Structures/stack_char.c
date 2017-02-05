#include<stdio.h>;
char stackdata[100];
int top=-1;

push(char x)
{
top++;
stackdata[top]=x;
}

char pop()
{
char x;
x=stackdata[top];
top--;
return x;
}

char peek()
{
    if(top==-1)
        return 0;
char x;
x=stackdata[top];
return x;
}

int isempty()
{
if(top==-1)
return 1;
else
return 0;
}

int isfull()
{
if(top==(100-1))
return 1;
else
 return 0;
 }

 initialize()
 {
 top=-1;
 }
