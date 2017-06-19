#include<iostream>

void del(int *ar, int pos, int n)
{
  for(int i = pos; i < n-1; i++)
    ar[i] = ar[i+1];
}
