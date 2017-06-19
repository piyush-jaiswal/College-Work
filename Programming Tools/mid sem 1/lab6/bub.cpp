#include<iostream>

using namespace std;

void swap(int *ar, int first, int second)
{
  int temp = ar[first];
  ar[first] = ar[second];
  ar[second] = temp;
}

void bub_sort(int* ar, int n)
{
  int i, j;
  
  for(i=0; i<n; i++)
  {
    for(j=0; j<n-i-1; j++)
    {
      if(ar[j] > ar[j+1])
        swap(ar, j, j+1);
    }
  }
}
