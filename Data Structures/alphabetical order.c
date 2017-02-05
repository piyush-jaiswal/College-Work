#include<stdio.h>
#include<string.h>

charsort(struct student a[],int size)
{
    int i,j,changehappened = 1;
    struct student dummy;
    while(changehappened)
    {
        changehappened = 0;
        for(i=0; i<size-1; i++)
        {
            if(strcmp(a[i].name,a[i+1].name)>0)
            {
                dummy = a[i];
                a[i] = a[i+1];
                a[i+1] = dummy;
                changehappened = 1;
            }
        }
    }
}
