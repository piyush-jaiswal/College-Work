/* 9) Assuming that a text file named FIRST.TXT contains some text written into it, write a function named vowelwords(), that reads the file FIRST.TXT and creates a new
 file named SECOND.TXT, to contain only those words from the file FIRST.TXT which start with a lowercase vowel (i.e., with 'a', 'e', 'i', 'o', 'u'). 
For example, if the file FIRST.TXT contains
Carry umbrella and overcoat when it rains
Then the file SECOND.TXT shall contain
umbrella and overcoat it.   */

#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

void vowelwords()
{
	ifstream fin("FIRST.txt");
	ofstream outf("SECOND.txt");
	int i,pos=0;
	char ch[80], c, temp[80];
	
	while(fin)
	{
		fin.getline(ch,80);
		cout<<ch<<endl;
		
		for(i=0; i<strlen(ch); i++)
		{
			if(ch[i]==' ' || ch[i]=='.' || ch[i]==',' || ch[i]=='!' )
			{
				c = temp[0];
				if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
				{
					cout<<temp<<" ";
					outf<<temp<<endl;
				}
				pos=0;
				memset(temp,0,sizeof(temp)); //Resetting the vaue of temp
			}
			else
				temp[pos++] = ch[i];
		}
	}
}

int main()
{
	vowelwords();
	return 0;
}

