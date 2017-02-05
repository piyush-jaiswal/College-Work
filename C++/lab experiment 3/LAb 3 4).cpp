/*LAB-3
4.	Wap to perform following operations on two or more complex no’s
a.	ADD    b. SUB   c. MUL.         */


#include<iostream>
#include<conio.h>

using namespace std;

class com
{
    public:
    int real,img;
    void add(com);
    void subtract(com);
    void multiply(com);
};

void com :: add(com a)
{
    int r,im;
    r = a.real + real;
    im = a.img + img;
    cout<<"Addition:"<<endl;
    cout<<r<<"+"<<im<<"i"<<endl;
}

void com :: subtract(com a)
{
    int r,im;
    r = real-a.real;
    im = img - a.img;
    cout<<"Subtraction:"<<endl;
    cout<<r<<"+"<<im<<"i"<<endl;
}

void com :: multiply(com a)
{
    int r,im;
    r = real*a.real - img*a.img;
    im = real*a.img + a.real*img;
    cout<<"Multiplication:"<<endl;
    cout<<r<<"+"<<im<<"i"<<endl;
}

int main()
{
    com a = com();
    com b = com();
    cout<<"Enter the complex nos real and img of both nos"<<endl;
    cin>>a.real>>a.img>>b.real>>b.img;
    a.add(b);
    a.subtract(b);
    a.multiply(b);
    getch();
    return 0;
}
