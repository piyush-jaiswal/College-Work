/* Q)  Now in the earlier program separate the stack implementation and paste it into another file called "stack.c". The main function would stay in a different file. In the program which contains the main program, include the stack.c using #include command. Then compile the code and execute. This should give you the same output as the first program.

Now you have stack.c as a working implementation of a stack. In whichever program you need a stack you can include this file.*/


#include<stdio.h>;
#include"stacks.c"

int main()
{
push(10);
push(12);
push(24);
printf("Popped value = %d\n", pop());
printf("Popped value =%d\n", pop());
getch();
return 0;
}
