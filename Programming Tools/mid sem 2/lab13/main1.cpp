#include<iostream>
#include "numprocess.h"

using namespace std;

int main()
{
  int n, i, ch=0;

  cout << "Enter number of elements: ";
  cin >> n;
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
       bub_sort(ar, n);
       returned = binary(ar, num, n);
       if(returned != -1)
         cout << endl << num << " is located at position " << returned << endl;
       else
         cout << "No such element" << endl;
       break;

      case 2:
        bub_sort(ar, n);
        cout << "List of sorted numbers: ";
		display(ar, n); 
        break;

      case 3:
        int num2, pos;
        cout << "Enter the number to delete ";
        cin >> num2;
        pos = binary(ar, num2, n);
        del(ar, pos, n);
        n -= 1;
        cout << "The new list after deletion: ";
        display(ar, n);
        break;
        
      case 4:
        int num3, pos2, pos3;
        cout << "Enter the number you want to insert: ";
        cin >> num3;
		cout << "Enter the position you want the number to get inserted in: " << endl;
    	cin >> pos2;
        n += 1;
	   	ins(ar, pos2, num3, n);
		cout << "The new list is: ";
		display(ar, n);
		break;
   
      case 5:
        cout << endl << "Bye!" << endl << endl;
        break;
    }
  }
  
  return 0;
} 

