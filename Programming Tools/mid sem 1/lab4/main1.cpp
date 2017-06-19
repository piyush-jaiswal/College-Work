#include<iostream>
#include "search.h"

using namespace std;

int main()
{
   int f, ch=0, dd, mm, yyyy;
   char c[100];
   
   while(ch != 3)
   {
      cout << endl << "**************Program to search******************************************" << endl;
      cout << "1. Enter 1 if you want to search details for a specified date" << endl;
      cout << "2. Enter 2 if you want to search details for a specified string" << endl;
      cout << "3. Enter 3 to exit" << endl;
      cout << "Please enter your choice:" << endl;
      cin >> ch;

    switch(ch)
    {
      case 1:
        cout << "Enter the day" << endl;
        cin >> dd;
        cout << "Enter the month:" << endl;
        cin >> mm;
        cout << "Enter the year:" << endl;
        cin >> yyyy;
        
        f = date_Search(dd, mm, yyyy);
        if(!f)
          cout<<"No details exist for the specified date\n";
        break;
      
      case 2:
        cout << "Enter search string" << endl;
        cin >> c;
        f = word_Search(c);
        if(!f)
          cout<<"No details exist for the specified string\n";
        break;
      
      case 3:
        cout << "Bye!\n";
        break;
        
    }
   }
  
   
   return 0;
}
