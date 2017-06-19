#include <iostream>
#include <climits>
#include <limits>

using namespace std;

bool checkLength(int n)
{
  int ct = 0, d;

  while(n > 0)
  {
    d = n % 10;
    n /= 10;
    ct++;
      
    if(ct > 3)
      return false;
  }

  return true;
}

int input ()
{
  int n;
  
  while(true)
  {
	  cout << "Enter the number : ";
	  cin >> n;
	  
	  if(cin.fail())
	  {
	  	cout << "The number is invalid" << endl;
	  }
	  
	  else if(checkLength(n))
	  {
		cout << "The number is valid" << endl;
		break;
	  }
	  
	  else 
		cout << "The number is invalid" << endl;
		
	cin.clear();
  	cin.ignore(numeric_limits<streamsize>::max(),'\n');
  }

	cout << "\n";
	cout << "yay";
  	return n;
}

int check()
{
  return input();
}
