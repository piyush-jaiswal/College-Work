/* List of Experiments
h) Write a C++ program to read marks in 6 subjects using vectors and find average marks     */

#include<iostream>
#include<conio.h>

using namespace std;

class marks
{
	int avg;
	int ar[6];
	public:
		void input();
		void compute();
		void display();
};

void marks :: input()
{
	cout<<"Enter marks of 6 subjects"<<endl;
	for(int i =0; i<6; i++)
		cin>>ar[i];
}

void marks :: compute()
{
	avg = 0;
	for(int i =0; i<6; i++)
		avg += ar[i];
	avg = avg/6;
}

void marks :: display()
{
	cout<<endl<<"The marks of the 6 subjects are:"<<endl;
	for(int i =0; i<6; i++)
		cout<<ar[i]<<endl;
	cout<<endl<<"The average is "<<avg<<endl;
}

int main()
{
	marks ob;
	ob.input();
	ob.compute();
	ob.display();
	getch();
	return 0;
}
