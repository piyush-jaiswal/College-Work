/* Q) Implement Merge sort algorithm( you should use the above merge function in this ). */





#include<stdio.h>
#include"func to merge sorted arrays.c"

mergesort(int list[], int size)
{
    if(size>1)
    {
        int mid, fh[size/2], sh[size-size/2], fhsize=0, shsize=0, i;
        mid = size/2;
        for(i=0; i<mid; i++)
            fh[i] = list[i];
        fhsize=i;
        for(; i<size; i++)
            sh[i-mid] = list[i];
        shsize = size-mid;
        mergesort(fh,fhsize);
        mergesort(sh,shsize);
        merge(list,fh,fhsize,sh,shsize);

    }
}

main()
{
    int list[] = {2,5,7,8,4,3,1,9,14,16,11,12};
    int n,i;
    n = sizeof(list)/sizeof(list[0]);

    printf("Size = %d\n", n);

    mergesort(list,n);

    for(i=0; i<n; i++)
        printf(" %d ", list[i]);
}
