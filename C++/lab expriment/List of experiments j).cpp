/* List of Ecperiments
j)	 Modify the class for ten customers.   */

#include<iostream>
#include<conio.h>

using namespace std;

class bank
{
	string name, type_acc;
	public:
		int bal;
		int acc_no;
		void input();
		void deposit(int);
		void withdraw(int);
		void display();
};

void bank :: input()
{
	bal = 0;
	cout<<"Enter your bank details"<<endl;
	cout<<"Enter your name, acc no, acc type"<<endl;
	cin>>name>>acc_no>>type_acc;
}

void bank :: deposit(int sum)
{
	bal += sum;
	cout<<"Current balance = "<<bal<<endl;
}

void bank :: withdraw(int sum)
{
	bal -= sum;
	cout<<"Current balance = "<<bal<<endl;
}

void bank :: display()
{
	cout<<name<<endl;
	cout<<type_acc<<endl;
	cout<<"Balance = "<<bal<<endl;
}

int main()
{
	int ch, sum, no, j, i;
	bank ob[3];
	cout<<"Enter details of three customers"<<endl;
	for(int i=0; i<3; i++)
		ob[i].input();
	do
	{
	cout<<endl<<"Enter your acc_no"<<endl;
	cout<<"Enter 0 to exit"<<endl;
	cin>>no;
	for(i=0; i<10; i++)
	{
		if(no==ob[i].acc_no)
		{
			j = i;
			break;
		}
	}
	
	if(i==10 && no!=0)
	{
		cout<<"Account not found. Enter again."<<endl;
		continue;
	}
		
	do
	{
		if(no==0)
			break;
		cout<<endl<<"Press 1 to deposit"<<endl;
		cout<<"Press 2 to withdraw"<<endl;
		cout<<"Press 3 to check balance"<<endl;
		cout<<"Press -1 to exit"<<endl;
		cout<<"Enter choice"<<endl;
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"Enter sum to be deposited"<<endl;
				cin>>sum;
				ob[j].deposit(sum);
				break;
			case 2:
				cout<<"Enter sum to be withdrawn"<<endl;
				cin>>sum;
				if(sum>ob[j].bal)
				{
					cout<<"Insufficient funds"<<endl;
					continue;
				}
				ob[j].withdraw(sum);
				break;
			case 3:
				ob[j].display();
				break;
		}
		
	
	 } while(ch!=-1);
}while(no!=0);
	 
	 	getch();
		return 0;
}
