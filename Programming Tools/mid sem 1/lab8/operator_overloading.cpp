#include <iostream>
#include <math.h>
#include "stick.h"

// overload the + operrator
Stick Stick :: operator+ (const Stick& ob)
{
  Stick returned;
  returned.len.meter = len.meter + ob.len.meter;
  returned.len.centimeter = len.centimeter + ob.len.centimeter;
  returned.len.meter += returned.len.centimeter / 100.0; //convert centimeters to meters
  returned.len.centimeter = fmod(returned.len.centimeter, 100.0); //reassign value of centimeters
  return returned;
}

// overload the == operator
bool Stick :: operator== (const Stick& ob)
{
  if((len.meter == ob.len.meter) && (len.centimeter == ob.len.centimeter))
    return true;
  return false;
}


