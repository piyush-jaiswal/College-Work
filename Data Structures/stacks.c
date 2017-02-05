#include<stdio.h>;
int stackdata[100];
int top=-1;

push(int x)
    {
top++;
stackdata[top]=x;
}

int pop()
{
int x;
x=stackdata[top];
top--;
return x;
}

int peek()
{
if(top==-1)
return 0;
else
{
int x;
x=stackdata[top];
return x;
}
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
