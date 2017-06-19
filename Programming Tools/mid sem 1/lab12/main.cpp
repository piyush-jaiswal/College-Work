#include <iostream>
#include "insSort.h"

using namespace std;

void display(int *ar, int n)
{
  int i;
  for(i=0; i<n; i++)
    cout << ar[i] << " ";
  cout << endl;
}

int main()
{
  int n, i;
  cout << "Enter the length" << endl;
  cin >> n;
  cout << "Enter the elements" << endl;
  
  int *ar = new int[n];
  for(i=0; i<n; i++)
    cin >> ar[i];

  insertionSort(ar, n);
  display(ar, n);
  
  return 0;
}
