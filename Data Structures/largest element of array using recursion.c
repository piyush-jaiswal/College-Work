/* Q) Largest element of an array using recursion. */

#include<stdio.h>

int largest(int *p, int i, int v, int l)
{
    if(i==l)
    return v;
    if(p[i]>v)
    return largest(p,i+1,p[i],l);
    else
    return largest(p,i+1,v,l);
}

int main()
{
    int l;
    int p[] = {2,3,4,7,6,9,5,2,15,19};
    l = largest(p,1,p[0],sizeof(p)/sizeof(p[0]));
    printf("%d\n", l);
}


