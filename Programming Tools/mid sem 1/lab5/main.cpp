#include<iostream>
#include"stringcheck.h"

using namespace std;

int main()
{
  int i;
  
  char** st = new char*[10];
  for(i=0; i<10; i++)
    st[i] = new char[20];

  st = lexi();
  
  cout << endl;
  
  reverse(st);
 	
  cout<<endl;	
  
   
  for(i=0; i<10; i++)
  {
    if(upperc(st[i]))
      cout << st[i] << " has atleast one uppercase letter" << endl;
    else
      cout << st[i] << " does not have any uppercase letter" << endl;
  }
  cout << endl;
  
  hello();
  cout << endl;
  
  return 0;
}
