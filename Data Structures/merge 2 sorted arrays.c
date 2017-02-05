/* Q) Write a program that would merge data from 02 sorted integer arrays into a 3rd array such that it stays sorted.
int a[100], b[100], c[100], asize=10, bsize=10, csize=20;*/


#include<stdio.h>
int a[100], b[100], c[100];
int asize=10, bsize=10, csize=20;
a[] = {4,6,8,9,10,12,16,18,25,27};
b[] = {1,2,3,5,7,11,13,14,15,17};

main()
{
    int i=0,j=0,cpos=0;
        while(i<asize && j<bsize)
        {
            if(a[i]<b[j])
            {
            c[cpos] = a[i];
            i++;
            }
            else
            {
            c[cpos] = b[j];
            j++;
            }
        cpos++;
        }
    if(i<asize)
    {
    for(; i<asize; i++)
    c[cpos++] = a[i];
    }
    else if(j<bsize)
    {
    for(; j<bsize; j++)
    c[cpos++] = b[j];
    }
    for(i=0;i<csize;i++)
        printf("%d\n", c[i]);
    }
