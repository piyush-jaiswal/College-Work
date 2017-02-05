#include<stdio.h>n
#include<stdlib.h>

int main()
{
    int n,val,r,i,epos,lpos,upos,t;
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    int ar[n];
    printf("Enter the elements\n");
    for(i=0; i<n; i++)
        scanf("%d", &ar[i]);

    srand(time(NULL));
    r = rand()%n;

    val = ar[r];
    printf("Pivot = %d\n", val);
    epos=0;
    lpos=0;
    upos=n-1;

    t = ar[0];
    ar[0] = ar[r];
    ar[r] = t;
    i=0;
    while(epos<=upos)
    {
        while(ar[i]>val && epos<=upos)
        {
            t = ar[i];
            ar[i] = ar[upos];
            ar[upos] = t;
            upos--;
        }

        if(ar[i]==val)
            epos++;
        if(ar[i]<val)
        {
            t = ar[i];
            ar[i] = ar[lpos];
            ar[lpos] = t;
            lpos++;
            epos++;
        }
        i++;
    }

    for(i=0; i<lpos; i++)
        printf("%d ",ar[i]);
    printf("\t");
    for(i=lpos; i<epos; i++)
        printf("%d ", ar[i]);
    printf("\t");
    for(i=upos+1; i<n; i++)
        printf("%d ", ar[i]);

    return 0;
}
