#include <iostream>
#include "stick.h"

using namespace std;

// Default constructor
Stick :: Stick ()
{
  len.meter = 1.0;
  len.centimeter = 0.0;
  cout << "Object created using default constructor" << endl;
}

// parameterized constructor
Stick :: Stick (double a, double b)
{
  len.meter = a;
  len.centimeter = b;
  cout << "Object created using parameterized constructor" << endl;
}
