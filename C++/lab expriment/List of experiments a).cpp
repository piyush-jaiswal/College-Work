/*LAB EXPERIMENTS-1
1.	Write a C++ program to convert centigrade into Fahrenheit. Formula:C=(F-32)/1.8. */

#include<iostream>
#include<conio.h>
using namespace std;
class temp
{
    public:
    float Cel;
    void getdata()
    {
        cout<<"Enter the Celius:";
        cin>>Cel;
    }
    void convert(float Cel)
    {
        int F;
        F=1.8*Cel +32;
        cout<<"Farenhiet="<<F<<endl;
    }
};
int main()
{
    temp ob;
    ob.getdata();
    ob.convert(ob.Cel);
    getch();
    return 0;
}

