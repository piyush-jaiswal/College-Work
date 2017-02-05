#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;

int bintodec(int x)
{
	int power=0, dec=0;
	while(x>0)
	{
		dec = dec+ x%10*(int)pow(2,power);
		x/=10;
		power++;
	}
	return dec;
}

int main()
{
	int x = bintodec(10);
	cout<<x<<endl;
	getch();
	return 0;
}
