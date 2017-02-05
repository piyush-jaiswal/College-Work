#include<stdio.h>

int main()
{
    int n,i,j,t,val;
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    int ar[n];
    printf("Enter the elements\n");
    for(i=0; i<n; i++)
        scanf("%d", &ar[i]);

    for(i=0; i<n; i++) // sorting
    {
        for(j=i+1; j<n; j++)
        {
            if(ar[j]<ar[i])
            {
                t = ar[i];
                ar[i] = ar[j];
                ar[j] = t;
            }
        }
    }

    printf("Enter the value\n");
    scanf("%d", &val);

    for(i=0,j=n-1;i<j;)
    {
        if((ar[i]+ar[j]) == val)
            break;
        if((ar[i]+ar[j]) > val)
            j--;
        if((ar[i]+ar[j]) < val)
            i++;
    }

    if(i==j)
        printf("Cannot be done\n");
    else
        printf("%d = %d + %d", val,ar[i],ar[j]);
    return 0;
}
