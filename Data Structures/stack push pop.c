/*Q)  Make one single program that contains the implementation of a stack and a main program to test the stack's working.
The stack should implement : push(), pop(), peek(), isempty(), isfull(), initialize().
The main function would simply use push and pop sequence and print the relevant data to see if what should happen theoreticallty is working practically also.*/


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
int x;
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

 int main()
 {
 push (10);
 push (12);
 push (15);
 printf("Popped value = %d\n", pop());
 printf("Popped value = %d\n", pop());
 push (24);
 printf("Peeked value = %d\n", peek());
 int y;
 y = isempty();
 if(y==1)
 printf("Stack is empty\n");
 else
 printf("Stack is not empty\n");
pop();
pop();
 y = isempty();
 if(y==1)
 printf("Stack is empty\n");
 else
 printf("Stack is not empty\n");
 y = isfull();
 if(y==1)
 printf("Stack is full\n");
 else
 printf("Stack is not full\n");
 getch();
 return 0;
 }

