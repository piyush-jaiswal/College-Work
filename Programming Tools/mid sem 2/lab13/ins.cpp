#include<iostream>

void ins(int *ar, int pos, int num, int n)
{
  for(int i=n-1; i>pos; i--)
    ar[i] = ar[i-1];
  ar[pos] =  num;
}
