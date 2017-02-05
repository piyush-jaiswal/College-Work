/* 8)copy from word */


#include<iostream>
#include<conio.h>
using namespace std;
class electricity
{
    int n;
    char name[20];
    int amount;
public:
    void getdata();
    void operation();
    void display();
};
void electricity::getdata()
{
    cout<<"enter the name of the customer : ";
    cin>>name;
    cout<<"enter the no. of units consumed : ";
    cin>>n;
}
void electricity::operation()
{
    if(n<=100)
        amount=50+60*n;
    else if(n>=100 && n<300)
        amount=50+80*n;
    else if(n>=300)
        {
            int m=50+90*n;
            amount=m+0.15*m;
        }
}
void electricity::display()
{
    cout<<"name of user : "<<name<<endl;;
    cout<<"no. of units consumed: "<<n<<endl;
    cout<<"amount to be paid: "<<amount<<endl;
}
int main()
{
    electricity ob;
    ob.getdata();
    ob.operation();
    ob.display();
    getch();
    return 0;
}
