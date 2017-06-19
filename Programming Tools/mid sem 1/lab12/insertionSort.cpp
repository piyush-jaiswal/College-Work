#include<iostream>

void insertionSort(int *ar, int n)
{
  int i=1, j, val;

  // insertion sort
  while(i < n)
  {
    j = i-1;
    val = ar[i];
    while(val < ar[j] && j >= 0)
      ar[j+1] = ar[j--];
    ar[j+1] = val;
    i++;
  }
}
