/* 2.	Wap to demonstrate the use of static variable for array of objects. */

#include<iostream>
#include<conio.h>;
using namespace std;
class student
{
    static int percentage;
    char name[20];
public:
    void getdata();
    void display();
};
int student::percentage=92;
void student::getdata()
{
    cout<<"enter the name of the student : ";
    cin>>name;
}
void student::display()
{
    cout<<"name of the student :"<<name<<endl;
    cout<<"percentage obtained :"<<percentage<<endl;
}
int main()
{
    int i;
    student ob[5];
    for(i=0;i<5;i++)
        ob[i].getdata();
    for(i=0;i<5;i++)
        ob[i].display();
    getch();
    return 0;
}

