#include<stdio.h>


bubblesort(struct student a[],int size)
{
    int i,j,changehappened = 1;
    struct student t;
    while(changehappened)
    {
        changehappened = 0;
        for(i=0; i<size-1; i++)
        {
            if(a[i].rollno>a[i+1].rollno)
            {
                t = a[i];
                a[i] = a[i+1];
                a[i+1] = t;
                changehappened = 1;
            }
        }
    }
}
