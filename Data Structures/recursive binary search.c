/*Q) Write a recursive version of Binary Search algorithm. */




#include<stdio.h>
int ar[100] = {0}, c=0;
int bsearch(int spos, int epos, int v)
{
    int mid;
    if(spos>epos)
        return -1;
    mid = (spos+epos)/2;
    c++;
    if(v>ar[mid])
        return bsearch(mid+1, epos, v);
    if(v<ar[mid])
        return bsearch(spos, mid-1, v);
    else
        return mid;
}

int main()
{
int len,v,spos=0,epos,f,i;
printf("Enter the length of the array\n");
scanf("%d", &len);
printf("Enter the elements in ascending order\n");
for(i=0;i<len;i++)
scanf("%d", &ar[i]);
printf("Enter the element to be searched\n");
scanf("%d", &v);
epos = len-1;
f = bsearch(spos,epos,v);
if(f==-1)
printf("Value not found\n");
else
printf("Value found at position %d\n", f+1);
printf("Total no. of comparisions = %d", c);
getch();
return 0;
}
