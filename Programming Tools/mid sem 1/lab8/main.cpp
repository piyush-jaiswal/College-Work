#include <iostream>
#include "stick.h"

using namespace std;

int main()
{
  double met, cen;
  
  cout << "Enter the length of stick 1" << endl;
  cout << "In meter : ";
  cin >> met;
  cout << "In centimeter : ";
  cin >> cen;
  Stick ob1(met, cen);
  
  cout << endl << "Enter the length of stick 2" << endl;
  cout << "In meter : ";
  cin >> met;
  cout << "In centimeter : ";
  cin >> cen;
  Stick ob2(met, cen);
  cout << endl;

  cout << endl << "Length of stick 1" << endl;
  ob1.display();
  cout << endl << "Length of stick 2" << endl;
  ob2.display();

  cout << endl << "Total length" <<  endl;
  Stick add = ob1 + ob2;
  add.display();

  bool f = (ob1 == ob2);
  if(f)
    cout << endl << "The sticks have equal length" << endl;
  else
    cout << endl << "The sticks have unequal length" << endl;

  return 0;
   
}
