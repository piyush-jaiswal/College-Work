/* 7)Write a function in C++ to count and display the number of lines not starting with alphabet 'A' present in a text file "STORY.TXT".
Example:
If the file "STORY.TXT" contains the following lines,
The rose is red.
A girl is playing there.
There is a playground.
An aeroplane is in the sky.
Numbers are not allowed in the password.

The function should display the output as 3. */ 



#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

int no_of_not_A()
{
    int ct = 0;
    char ch[80];
    ifstream fin;
    fin.open("Story.txt");
    cout<<"Story.txt opened"<<endl;
    cout<<"Contents:"<<endl<<endl;
    while(fin)
    {
        fin.getline(ch,80 ,'\n');
        cout<<ch<<endl;
        if(!(ch[0] == 'A'))
            ct++;
    }
    fin.close();
    return ct-1;
}

int main()
{
	cout<<"No. of lines not starting with A = "<<no_of_not_A()<<endl;

    return 0;
}
