#include<stdio.h>
#include<conio.h>
#include<math.h>

int findLimit(int ar[]) // find the upper limit
{
    int i=0, p=0;
    while(i<1000)
    {
        if(ar[i]==99999)
            return i;
        p++;
        i = (int)pow(2,p);
    }
}

void bsearch(int ar[], int lim, int val) // binary search
{
    int low=0, up=lim, mid, f=0;

    while(low<=up)
    {
        mid = (int)((low+up)/2);
        if(ar[mid]==val)
        {
            f=1;
            break;
        }
        if(val>ar[mid])
            low=mid+1;
        else if(val<ar[mid])
            up=mid-1;
    }
    if(f==0)
        printf("Value not found\n");
    else
        printf("Value found at %d\n", mid+1);
}

int main()
{
    int ar[1000], i;
    for(i=0; i<1000; i++)
        ar[i] = 99999;
    printf("Enter the array in sorted order\n");
    printf("-1 to exit\n");
    int ch, pos=0, lim, val;
    do
    {
        scanf("%d", &ch);
        if(ch!=-1)
            ar[pos++] = ch;
    }while(ch!=-1);

    lim = findLimit(ar);
    do
    {
    printf("\nEnter the value to be found\n");
    scanf("%d", &val);
    bsearch(ar, lim, val);
    printf("\n0 to exit, any other to continue\n");
    scanf("%d", &ch);
    }while(ch!=0);

    getch();
    return 0;
}
