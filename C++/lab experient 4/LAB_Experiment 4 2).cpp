/*2.	Wap to overload the following operator using friend function for string:
a.	( <) less than operator                 c. ( > ) greater than operator
b.	(==) operator 		*/

#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

class compare
{
 	  char *ch;
 	  public:
	  		 compare()
	  		 {
  		  	    cout<<"Enter the string"<<endl;
	  		    ch = new char;
  		  	    cin >> ch;					 
             }
             
	  		 friend bool operator< (compare &a, compare &b);
			 friend bool operator> (compare &a, compare &b);
			 friend bool operator== (compare &a, compare &b);
};

bool operator< (compare &a, compare &b) //checks whether a is less than b alphabatically
{
 	 if(strcmp(a.ch, b.ch)< 0)
		 return true;
     return false;
}

bool operator> (compare &a, compare &b) //checks whether a is greater than b alphabatically
{
 	 if(strcmp(a.ch, b.ch)> 0)
		 return true;
     return false;
}

bool operator== (compare &a, compare &b)  //checks whether a is equal to b alphabatically
{
 	 if(strcmp(a.ch, b.ch)== 0)
		 return true;
     return false;
}

int main()
{
 	compare a;
 	compare b;
 	bool x;
 	x = a<b;
 	cout<<endl<<"True = 1   False = 0"<<endl;
	cout<<endl<<"A<B = "<< x <<endl;
	x = a>b;
	cout<<endl<<"A>B = "<< x <<endl;
	x = a==b;
	cout<<endl<<"A==B = "<< x <<endl;
 	getch();
 	return 0;
}
