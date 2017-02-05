/*Q) Implement sequential search algorithm. ( scan the entire array from beginning till end until you find it or you reach the end of the array ).
Keep the search array as a numeric array, initialized at time of declaration and keep it global.
The program should ask for a value to search, and then tell the location where it is found.
If the value is not found the program should display not found.

Additionally the program should display the total number of comparisons done to locate the value ( or realize that the value was not found )*/




#include<stdio.h>
int ar[100] = {0};

int main()
{
    int com=0,i,len,x;
    printf("Enter the length of the array\n");
    scanf("%d", &len);
    printf("Enter the elements\n");
    for(i=0;i<len;i++)
    scanf("%d", &ar[i]);
    printf("Enter the value to be searched\n");
    scanf("%d", &x);
    for(i=0;i<len;i++)
    {
    com++;
    if(ar[i]==x)
    {
    printf("Value found at position %d\n", i+1);
    break;
    }
    }
    if(i==len)
    printf("Value not found\n");
    printf("Total no. of comparisions = %d\n", com);
    getch();
    }
