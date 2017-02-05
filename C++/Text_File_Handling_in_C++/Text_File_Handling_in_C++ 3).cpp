/* 3) Write a user-defined function in C++ to read the content from a text file OUT.TXT, count and display the number of alphabets present in it.     */

#include<iostream>
#include<conio.h>
#include<fstream>
#include<ctype.h>
#include<string.h>

using namespace std;

void user_defined()
{
	int i, ct=0;
	ifstream inf;
	inf.open("OUT.txt");
	cout<<"OUT.txt opened"<<endl;
	cout<<"Contents:"<<endl;
	char ar[80];
	while(inf) // reading the contents
	{
		inf.getline(ar, 80); //storing contents in ar 80 at a time
		cout<<ar;
		
		for(i=0; i<strlen(ar); i++) //counting the no. of alphabets
		{
			if(isalpha(ar[i]))
				ct++;
		}
	}
	
	cout<<endl<<"No. of characters = "<<ct<<endl;	
	inf.close();
}

int main()
{
	user_defined();
	return 0;
}
