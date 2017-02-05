/*2.	Write a C++ program that declares two integers, determines whether the first is a multiple of the second and print the result. (Hint: Use the remainder 
operator).  */
#include<iostream>
#include<conio.h>
using namespace std;
class mult
{
public:
    int a;
    int b;
    void getdata()
    {
        cout<<"Enter the 1st no.";
        cin>>a;
        cout<<"Enter the 2nd no.";
        cin>>b;
    }
    void multiple(int a1,int a2)
    {
        if(a1%a2==0)
            cout<<"a is multiple of b"<<endl;
        else
            cout<<"a is not a multiple of b"<<endl;
    }
};

int main()
{
    mult ob;
    ob.getdata();
    ob.multiple(ob.a,ob.b);
    getch();
    return 0;
}

