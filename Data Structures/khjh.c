#include<stdio.h>

void isprint(int *q, int l)
{
    int i=0;
    while(i< l)
    {
    printf("%d\n", q[i]);
    i++;
    }
}


int main()
{
int p[] = {5,6,7,4,11,26,3,4};
int t =  sizeof(p)/sizeof(p[0]);
isprint(p,t);
}





