#include<iostream>
#include<conio.h>
using namespace std;
int x=100;

class io
{
	public:
	int x = 21;
};
int main()
{
    int x=20;
  {
        int x=30;
        cout<<"inner block"<<x<<endl;
    {
        int x=50;
        cout<<"innermost block"<<x<<endl;
        cout<<"scope_in_innnermost"<<::x<<endl;
        io ob;
        cout<<"scope in class"<<ob.x<<endl;
    }
  }
    getch();
    return 0;
}
