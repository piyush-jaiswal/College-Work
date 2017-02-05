/* LAB_Experiment 2
Do all these questions by applying concept of static data member, static member function,
const member function, inline function( Explicit , Implicit), nesting member function and Default Arguments:

1. Create a class employee that includes firstname( type String), lastname(type String) and a monthly
salary. Create two employee objects and display each object's yearly salary. Give each employee a 10% raise
 and display each employee‟s yearly salary.      */


#include<iostream>
#include<conio.h>

using namespace std;

class employee
{
    string firstname, lastname;
    static int msal;
public:
    void getdata();
    static int cal();
    void display();
    void raise();
};
int employee :: msal = 25000;

inline void employee :: getdata()
{
    cout<<"Enter the firstname and lastname"<<endl;
    cin>>firstname>>lastname;
}

inline int employee :: cal()
{
    return msal*12;
}

inline void employee :: display()
{
    cout<<endl<<firstname<<" "<<lastname<<endl;
    cout<<"Yearly salary "<<cal()<<endl;
}

inline void employee :: raise()
{
    cout<<"Salarty after 10 % raise = "<<cal()+.1*cal()<<endl;
}
int main()
{
    employee ob1, ob2;
    cout<<"Enter details of first employee"<<endl;
    ob1.getdata();
    ob1.display();
    ob1.raise();
    cout<<endl;
    cout<<"Enter details of second employee"<<endl;
    ob2.getdata();
    ob2.display();
    ob2.raise();
}

