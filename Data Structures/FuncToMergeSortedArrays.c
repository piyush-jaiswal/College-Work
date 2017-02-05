/* Q)  Write a function to merge two integer arrays into a third array as sorted. The function should work as follows:
    int list[100],a[100],b[100], asize, bsize; // put suitable data as required but keep array sizes as 100

    lsize=merge(list, a, asize, b, bsize);

    after this the data of array a and b should be merged in list and the size of the merged data should be returned. */



#include<stdio.h>

int merge(int *list,int *a,int asize,int *b,int bsize)
{
    printf("Function called: \n\n------");
    getch();
    int i=0,j=0,list_pos=0;
    while(i<asize && j<bsize)
        if(a[i]<=b[j])
    {
        list[list_pos++] = a[i];
        i++;
    }
    else
    {
        list[list_pos++] = b[j];
        j++;
    }
    if(i<asize)
    {
        while(i<asize)
            list[list_pos++] = a[i++];
    }
    else if(j<bsize)
    {
        while(j<bsize)
            list[list_pos++] = b[j++];
    }
    for(i=0;i<list_pos;i++)
        printf("%d\n", list[i]);
    return list_pos;
}
