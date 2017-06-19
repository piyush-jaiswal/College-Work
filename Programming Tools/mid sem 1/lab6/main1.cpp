#include<iostream>
#include "numprocess.h"

using namespace std;

// returns true when the array size is about to be full or when the array has unused space
bool isCloseEnough(int n, int noOfElements)
{
    if(n == noOfElements)
      return true;
    return false;
}

// allcoate new array of size 'size'
int* allocateNewArray(int *ar, int noOfElements, int size)
{
  int *ar2 = new int(size);
  for(int i = 0; i < noOfElements; i++)
    ar2[i] = ar[i];
  delete ar;
  return ar2;
}

void display(int *ar, int n)
{
  int i;
  for(i=0; i<n; i++)
    cout << ar[i] << " ";
  cout << endl;
}

int main()
{
  int n, i, ch=0, noOfElements;

  cout << "Enter number of elements: ";
  cin >> n;
  noOfElements = n;
  int *ar = new int(n);

  cout << "Enter " << n << " numbers" << endl;
  for(i=0; i<n; i++)
    cin >> ar[i];

  while(ch != 5)
  {
   cout << endl << "Please enter your choice:" << endl;
   cout << "Enter 1 to perform binary search" << endl;
   cout << "Enter 2 to perform bubble sort" << endl;
   cout << "Enter 3 to delete a particular number" << endl;
   cout << "Enter 4 to insert a number" << endl;
   cout << "Enter 5 to exit" << endl;
   cin >> ch;
   
   switch(ch)
   {
     case 1:
       int num, returned;
       cout << "Enter the number you want to search ";
       cin >> num;
       bub_sort(ar, noOfElements);
       returned = binary(ar, num, noOfElements);
       if(returned != -1)
         cout << endl << num << " is located at position " << returned << endl;
       else
         cout << "No such element" << endl;
       break;


      case 2:
        bub_sort(ar, noOfElements);
        cout << "List of sorted numbers: ";
		display(ar, noOfElements); 
        break;


      case 3:
        int num2, pos;
        cout << "Enter the number to delete ";
        cin >> num2;
        pos = binary(ar, num2, noOfElements);
        del(ar, pos, noOfElements);
        noOfElements--;
        
        // decreasing array size dynamically
        if(isCloseEnough(n/2, noOfElements))
        {
          ar = allocateNewArray(ar, noOfElements, n/2);
          n /= 2;
        }
        cout << "The new list after deletion: ";
        display(ar, noOfElements);
        break;

        
      case 4:
        int num3, pos2, pos3;
        cout << "Enter the number you want to insert: ";
        cin >> num3;
        cout << "Enter the position you want the number to get inserted in: ";
        cin >> pos2;

        //Increasing array size dynamically
        if(isCloseEnough(n, noOfElements))
        {
          ar = allocateNewArray(ar, noOfElements, n*2);
          n *= 2;
        }
        noOfElements++;
        ins(ar, pos2, num3, noOfElements);
        cout << "The new list is: ";
        display(ar, noOfElements);
        break;

   
      case 5:
        delete ar;
        cout << "Bye!" << endl << endl;
        break;
    }
  }
  
  return 0;
}