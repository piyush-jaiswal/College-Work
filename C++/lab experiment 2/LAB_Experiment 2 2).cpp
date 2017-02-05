/*LAB_Experiment 2
Do all these questions by applying concept of static data member, static member function, const member function,
inline function( Explicit , Implicit), nesting member function and Default Arguments:

2. Write a C++ program that reads digits and computes them into integers. For example 123 is read as the
 characters 1,2 and 3. The program should output “123 is 1 hundred and 2 tens and 3 ones”. The number should
 be output as an int value. Handle numbers with one, two, three or four digits. Hint: to get the integer value
  5 of the character „5‟ subtract „0‟ that is „5‟-„0‟==5.     */



#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

class read
{
	char num[4];
	int ar[4];
	int ln;
	public:
		void input();
		void compute();
		void display();
};

inline void read :: input()
{
	cout<<"Enter the number"<<endl;
	cin>>num;
}

void read :: compute()
{
	int i=0;
	ln = strlen(num);
	for(i=0; i<ln; i++)
		ar[i] = num[i] - '0';
}

void read :: display()
{
	cout<<"ln = "<<ln<<endl;
	if(ln==1)
	{
		if(ar[0]==1)
			cout<<ar[0]<<" one"<<endl;
		else
			cout<<ar[0]<<" ones"<<endl;
	}


	if(ln==2)
	{
		if(ar[0]==1)
			cout<<ar[0]<<" ten and ";
		else
			cout<<ar[0]<<" tens and ";
		if(ar[1]==1)
			cout<<ar[1]<<" one"<<endl;
		else
			cout<<ar[1]<<" ones"<<endl;
	}



	if(ln==3)
	{
		if(ar[0]==1)
			cout<<ar[0]<<" hundred and ";
		else
			cout<<ar[0]<<" hundreds and ";
		if(ar[1]==1)
			cout<<ar[1]<<" ten and ";
		else
			cout<<ar[1]<<" tens and ";
		if(ar[2]==1)
			cout<<ar[2]<<" one"<<endl;
		else
			cout<<ar[2]<<" ones"<<endl;
	}


	if(ln==4)
	{
		if(ar[0]==1)
			cout<<ar[0]<<" thousand and ";
		else
			cout<<ar[0]<<" thousands and ";
		if(ar[1]==1)
			cout<<ar[1]<<" hundred and ";
		else
			cout<<ar[1]<<" hundreds and ";
		if(ar[2]==1)
			cout<<ar[2]<<" ten and ";
		else
			cout<<ar[2]<<" tens and ";
		if(ar[3]==1)
			cout<<ar[3]<<" one"<<endl;
		else
			cout<<ar[3]<<" ones"<<endl;
	}
}

int main()
{
	read ob;
	ob.input();
	ob.compute();
	ob.display();
	getch();
	return 0;
}



