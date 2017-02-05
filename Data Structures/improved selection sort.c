
#include<stdio.h>
int a[] = {10,75,1,3,4,15,16,14,11};

main()
{
    int i,j,t,minpos;
    for(i=0; i<(sizeof(a)/sizeof(a[0])-1); i++)
    {
        minpos=i;
    for(j=i+1; j<(sizeof(a)/sizeof(a[0])); j++)
    {
    if(a[j]<a[minpos])
    minpos=j;
    }
    if(minpos!=i)
    {
    t = a[i];
    a[i]=a[minpos];
    a[minpos]=t;
    }
    }
    for(i=0; i<(sizeof(a)/sizeof(a[0])); i++)
        printf("%d\n", a[i]);
}
