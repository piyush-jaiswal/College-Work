/* 4) Write a function to count the number of blank present in a text file named "OUT.TXT".  */

#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

void no_of_blanks()
{
	ifstream inf("OUT.txt");
	int ct=0, i;
	char ar[80];
	while(inf) 
	{
		inf.getline(ar, 80); //storing contents in ar 80 at a time
		cout<<ar;
		
		for(i=0; i<strlen(ar); i++) //counting the no. of alphabets
		{
			if(ar[i]== ' ')
				ct++;
		}
	}
	
	cout<<endl<<"No. of blank spaces = "<<ct<<endl;	
	inf.close();
}

int main()
{
	no_of_blanks();
	return 0;
}
