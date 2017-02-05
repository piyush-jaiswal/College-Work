/* List of Experiments

i)	Define a class to represent a bank account . include the following members, data members:
1.	Name of the depositor
2.	Account no
3.	Type of account
4.	Balance amount in the account.
Member functions:
1.	To assign the initial values.
2.	To deposite an amount.
3.	To withdraw an amount after checking the balance.
4.	To display name and balance.
Write a program and test it.
*/

#include<iostream>
#include<conio.h>

using namespace std;

class bank
{
	string name, type_acc;
	int acc_no;
	public:
		int bal;
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
	int ch, sum;
	bank ob;
	ob.input();
	do
	{
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
				ob.deposit(sum);
				break;
			case 2:
				cout<<"Enter sum to be withdrawn"<<endl;
				cin>>sum;
				if(sum>ob.bal)
				{
					cout<<"Insufficient funds"<<endl;
					continue;
				}
				ob.withdraw(sum);
				break;
			case 3:
				ob.display();
				break;
		}
		
	
	 } while(ch!=-1);
	 
	 	getch();
		return 0;
}
