#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;


typedef struct date
{
  int dd;
  int mm;
  int yyyy;
} Date;


class Person
{
  private:
    char *name;
    int age;
    Date dob;

  public:
    void input();
    void display();
    friend ofstream& operator <<(ofstream&, const Person*);
    friend ifstream& operator >>(ifstream&, Person*);
};


// Operator overloading for structures
ofstream& operator <<(ofstream& out, const Date& dob)
{
  out << dob.dd << "/" << dob.mm << "/" << dob.yyyy;
  return out;
}


ifstream& operator >>(ifstream& in, Date& dob)
{
  char *temp = new char(12);
  in.getline(temp, 100, '/');
  dob.dd = atoi(temp);
  in.getline(temp, 100, '/');
  dob.mm = atoi(temp);
  in.getline(temp, 100, ' ');
  dob.yyyy = atoi(temp);

  delete temp;
  return in;
}


// Operator overloading for class
ofstream& operator <<(ofstream& out, const Person* p)
{
  out << p -> name << " ";
  out << p -> dob << " " << p -> age << endl;
  return out;
}


ifstream& operator >>(ifstream& in, Person *p)
{
  in >> p -> name;
  in >> p -> dob;
  in >> p -> age;

  return in;
}


void Person :: input()
{
  Person *p = new Person();

  cout << "Name : ";
  p -> name = new char(30);
  cin >> p -> name;
  cout << "DOB in dd/mm/yyyy: ";
  scanf("%d/%d/%d",  &p -> dob.dd, &p -> dob.mm, &p -> dob.yyyy);
  cout << "Age: ";
  cin >> p -> age;

  ofstream out;
  out.open("record", ios::app);
  out << p;
  out.close();

  cout << "Successfully entered!" << endl << endl;
  delete p -> name;
  delete p;
}


void Person :: display()
{
  ifstream in;
  in.open("record");
  cout << endl;
  
  while(in.good())
  {
    if(in.tellg())
      in.unget();

    Person *p = new Person();
    p -> name = new char(20);
    in >> p;
    in.get();
    in.get();
    cout << p -> name << " " << p -> dob.dd << "/" << p -> dob.mm << "/" << p -> dob.yyyy << " " << p -> age << endl;
    delete p -> name;
    delete p;
  }

  cout << endl;
  in.close();
}


int main()
{
  int ch;
  Person *p;
  ofstream out("record", ios::trunc);
  out.close();

  while (ch != 3)
  {
    cout << "Enter 1 for new entry" << endl;
    cout << "Enter 2 for showing records" << endl;
    cout << "Enter 3 to exit" << endl;
    cout << "Enter your choice." << endl;
    cin >> ch;

    switch(ch)
    {
      case 1:
        p -> input();
        break;

      case 2:
        p -> display();
        break;

      case 3:
        break;

      default:
        cout << "Invalid choice. Re-enter." << endl;
    }
  }

  return 0;
}
