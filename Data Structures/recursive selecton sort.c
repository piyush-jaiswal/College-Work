/* Q) Write a function/program to sort a numeric array using selection sort algorithm recursively. */


#include<stdio.h>

int *select_sort_rec(int i, int j, int *p, int l)
{
    int t;
    if(i==l-1)
    return p;
    if(j==l)
    return select_sort_rec(i+1, i+2, p,l);
    else
    {
    if(p[j]<p[i])
    {
    t=p[i];
    p[i]=p[j];
    p[j]=t;
    }
    return select_sort_rec(i, j+1, p,l);
    }
}

int main()
{
    int i=0, *q;
    int p[] = {2,3,4,7,6,9,5,2,15,19};
    q=select_sort_rec(0,1,p,sizeof(p)/sizeof(p[0]));
    while(i< sizeof(p)/sizeof(p[0]))
    {
    printf("%d\n", q[i]);
    i++;
    }
    getch();
    return 0;
}

