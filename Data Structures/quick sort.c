/* Q) Implement the quicksort algorithm on an integer array. */



#include<stdio.h>

int a[] = {5,4,3,2,9,11,1,3,4,7};

int divide(int low,int high)
{
    int mid,lastsmall=low,t,i;
    mid = (low+high)/2;
    t = a[low];
    a[low]=a[mid];
    a[mid]=t;
    for(i=low+1;i<=high;i++)
    {
        if(a[i]<a[low])
        {
            lastsmall++;
            t=a[lastsmall];
            a[lastsmall]=a[i];
            a[i]=t;
        }
    }
    t=a[low];
    a[low]=a[lastsmall];
    a[lastsmall]=t;
    return lastsmall;
}



quicksort(int low, int high)
{
    if(low<high)
    {
        int pivotlocation;
        pivotlocation = divide(low,high);
        quicksort(low,pivotlocation);
        quicksort(pivotlocation+1,high);
    }
}

int main()
{
    int i;
    printf("Before sorting: \n");
    for(i=0;i<10;i++)
        printf("% d ", a[i]);
    printf("\n\n");
    quicksort(0,9);
    printf("After sorting \n");
    for(i=0;i<10;i++)
        printf("% d ", a[i]);
}
