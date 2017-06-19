#include<iostream>

// performing binary search
int binary(int* ar, int num, int n)
{
  int low=0, high=n-1, mid;

   while(low <= high)
   {
     mid = (low+high)/2;
     if(ar[mid] > num)
       high = mid - 1;
     else if(ar[mid] < num)
       low = mid + 1;
     else
       break;
   }

  if(ar[mid] == num)
    return mid;
  return -1;
}


