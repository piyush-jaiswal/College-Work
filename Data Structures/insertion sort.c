/* Q) Implement Insertion Sort algorithm to sort an integer array.  */



#include<stdio.h>
int a[] = {10,5,7,9,6,4,3,6};
int max = sizeof(a)/sizeof(a[0]);
insertion_sort()
{
    int i,j,t;
    for(i=1; i<max; i++)
    {
        j=i;
        t=a[i];
        while(j>0)
        {
            if(a[j-1]<t)
                break;
            a[j]=a[j-1];
            j=j-1;
        }
        a[j]=t;
    }
    for(i=0; i<max; i++)
    {
        printf("%d\n", a[i]);
    }
}

int main()
{
    insertion_sort();
}
