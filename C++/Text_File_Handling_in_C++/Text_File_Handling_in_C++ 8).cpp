/*  8)Assuming that a text file named FIRST.TXT contains some text written into it, write a function named copyupper(), that reads the file FIRST.TXT 
and creates a new file named SECOND.TXT contains all words from the file FIRST.TXT in uppercase.  */

#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

void copyupper()
{
	ifstream fin("FIRST.txt");
	ofstream fout("SECOND.txt");
	char ch[80], c, upper[80];
	int i, pos=0;
	
	while(fin)
	{
		fin.getline(ch,80);
		cout<<ch<<endl;
		for(i=0; i<80; i++)
		{
			c = toupper(ch[i]);
			upper[pos++] = c;
		}
		fout<<upper;
		cout<<upper<<endl;
		pos=0;
	}
	fin.close();
	fout.close();
}

int main()
{
	copyupper();
	return 0;
}
