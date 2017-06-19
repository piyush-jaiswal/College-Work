#include <iostream>
#include "numprocess.h"

using namespace std;

int main()
{
  int n = check();
  if(armstrong(n))
    cout << n << " is a an Armstrong number" << endl;
  else
     cout << n << " is a not an Armstrong number" << endl;
   cout << "The first digit is " << first(n);
   return 0;
}
