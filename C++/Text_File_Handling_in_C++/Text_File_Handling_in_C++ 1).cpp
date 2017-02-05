/* 1. Write a C++ program to write number 1 to 100 in a data file NOTES.TXT.    */

#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

int main()
{
	ofstream outf("NOTES.txt");
	int i;
	for(i=1; i<=100; i++)
	{
		outf<<i<<endl;
	}
	outf.close();
	return 0;
}
