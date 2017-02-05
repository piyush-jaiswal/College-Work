#include<iostream>
#include<conio.h>

using namespace std;

int dectobin(int x)
{
	int pv=1, bin=0;
	while(x>0)
	{
		bin = bin+x%2*pv;
		x/=2;
		pv*=10;
	}
	return bin;
}

int main()
{
	int x = dectobin(5);
	cout<<x<<endl;
	getch();
	return 0;
}
