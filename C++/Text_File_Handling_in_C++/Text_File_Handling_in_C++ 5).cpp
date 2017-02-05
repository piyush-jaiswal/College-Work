/* 5) Write a function to count number of words in a text file named "OUT.TXT".   */

#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

void no_of_words()
{
	ifstream inf("OUT.txt");
	int ct=0, i;
	char ar[80];
	while(inf) 
	{
		inf.getline(ar, 80); //storing contents in ar 80 at a time
		cout<<ar;
		
		char ar1[100] = " ";
		strcat(ar1,ar);
		for(i=0; i<strlen(ar1); i++) //counting the no. of words
		{
			if(ar1[i]== ' ')
			{
				if(isalpha(ar1[i+1])) //condition for letter
					ct++;
			}
		}
	}
	
	cout<<endl<<"No. of words = "<<ct<<endl;	
	inf.close();
}

int main()
{
	no_of_words();
	return 0;
}
