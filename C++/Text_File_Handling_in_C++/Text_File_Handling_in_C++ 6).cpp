/* 6) Write a function in C++ to print the count of word the as an independent word in a text file STORY.TXT.
for example, if the content of the file STORY.TXT is
There was a monkey in the zoo. The monkey was very naughty.
Then the ouput of the program should be as 2.   */

#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

int no_of_the()
{
	ifstream inf("Story.txt");
	cout<<"Contents:"<<endl;
	int i, pos=0, ct=0;
	char ar[80], wr[80];
	
	while(inf)
	{
		inf.getline(ar,80);
		cout<<ar;
		
		for(i=0; i<strlen(ar); i++)
		{
			if(ar[i]==' ' ||ar[i]=='.' ||ar[i]=='!')
			{
				if(!stricmp(wr,"the"))
					ct++;
				pos=0;
				memset(wr,0,sizeof(wr)); // resets the wr array using memset(destination, value(source), no. of bytes);
			}
			else
				wr[pos++] = ar[i];
		}
	}
	inf.close();
	return ct;
}

int main()
{
	int t = no_of_the();
	cout<<endl<<"No. of the's = "<<t<<endl;
	return 0;
}

