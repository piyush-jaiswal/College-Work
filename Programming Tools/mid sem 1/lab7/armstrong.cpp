#include <iostream>

bool armstrong(int n)
{
  int cp = n, s=0;

  while(cp > 0)
  {
    s += n % 10;
    n /= 10;
  }

  if(s == n)
    return true;
  return false;
}
