/* Q)  Write code to implement bubble sort algorithm to sort a global integer array.  */



#include<stdio.h>
int a[] = {10,75,1,3,4,15,16,14,11};

main()
{
    int i,j,t,changehappened = 1;
    while(changehappened)
    {
    changehappened = 0;
    for(i=0; i<(sizeof(a)/sizeof(a[0])-1); i++)
    {
    if(a[i]>a[i+1])
    {
    t = a[i];
    a[i] = a[i+1];
    a[i+1] = t;
    changehappened = 1;
    }
    }
    }
    for(i=0; i<(sizeof(a)/sizeof(a[0])); i++)
        printf("%d\n", a[i]);
}
