/*List of Expeiments
c) Write a C++ program that prompts the user to enter two integer values in int variables val1, val2 and find largest, sum, difference, 
product and ratio of these values.  */

#include <iostream>
#include<conio.h>
#include<math.h>

using namespace std;

class operate
{
	int val1, val2;
	
	public:
		
		void input()
		{
			cout<<"Enter two integer values"<<endl;
			cin>>val1>>val2;
		}
		
		int largest()
		{
			if(val1>val2)
				return val1;
			else if(val1==val2)
				return -1;
			else
				return val2;
		}
		
		int sum()
		{
			return val1+val2;
		}
		
		int difference()
		{
			return abs(val1-val2);
		}
		
		int product()
		{
			return val1*val2;
		}
		
		double ratio()
		{
			return (double)val1/val2;
		}
		
			void display()
		{
			cout<<"The largest number is "<<largest()<<endl;
			cout<<"The sum is "<<sum()<<endl;
			cout<<"The difference is "<<difference()<<endl;	
			cout<<"The product is "<<product()<<endl;
			cout<<"The ratio is "<<ratio()<<endl;
		}
		
};

int main()
{
	operate b;
	b.input();
	b.display();
}

