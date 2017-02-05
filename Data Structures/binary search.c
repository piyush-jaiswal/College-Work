/* Q) Implement the binary search algorithm in a non-recursive manner.

Keep the search array as a numeric array, initialized at time of declaration and keep it global.
The program should ask for a value to search, and then tell the location where it is found.
If the value is not found the program should display not found.

Additionally the program should display the total number of comparisons done to locate the value ( or realize that the value was not found )*/






#include<stdio.h>
int ar[100] = {0};

int main()
{
    int com=0,i,len,x,mid,spos=0,epos;
    printf("Enter the length of the array\n");
    scanf("%d", &len);
    printf("Enter the elements in ascending order\n");
    for(i=0;i<len;i++)
    scanf("%d", &ar[i]);
    printf("Enter the value to be searched\n");
    scanf("%d", &x);
    epos = len-1;
    while(spos<=epos)
    {
    mid = (spos+epos)/2;
    com++;
    if(ar[mid]==x)
    {
    printf("Value found at position %d\n", mid+1);
    break;
    }
    else if(x>ar[mid])
            spos = mid+1;
        else
            epos=mid-1;

    }
    if(spos>epos)
    printf("Value not found\n");
    printf("Total no. of comparisions = %d", com);
    getch();
    }
