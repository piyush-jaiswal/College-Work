#include <iostream>

using namespace std;

int no = 1;

class bank
{
  private:
    char name[20];
    int accNo;
    char typeOfAccount[20];
    double balance;

  public:
    bank();
    void deposit(double);
    void withdraw(double);
    void display();  
};

bank :: bank ()
{
  cout << "Name: ";
  cin >> name;
  
  cout << "Account type: ";
  cin >> typeOfAccount;

  accNo = no++;
  balance = 0.0;

  display();
}

void bank :: deposit (double amount)
{
  cout << "Trying to deposit...." << endl;
  cout << "Before:" << endl;
  display();
  balance += amount;
  cout << "After:" << endl;
  display();
}

void bank :: withdraw (double amount)
{
  cout << "trying to withdraw" << endl;
  cout << "Current:" << endl;
  display();
  if(amount > balance)
  {
    cout << "Error. Insufficient funds!" << endl << endl ;
    return;
  }
  balance -= amount;
  cout << "After" << endl;
  display();
}

void bank :: display ()
{
  cout << "Name: " << name << endl;
  cout << "Balance = Rs " << balance << endl << endl;
}

int main()
{
  cout << "First customer" << endl;
  bank *ob1 = new bank();
  cout << "Second customer" << endl;
  bank *ob2 = new bank();
  ob1 -> withdraw(50.00);
  ob1 -> deposit(1000.00);
  ob1 -> withdraw(200.00);

  ob2 -> deposit(5000.00);
  ob2 -> withdraw(3000.00);
  
  return 0;
}
