/* 2) Write a C++ program, which initializes a string variable to the content "Time is a great teacher but unfortunately it kills all its pupils. Berlioz" 
and outputs the string to the disk file OUT.TXT. you have to include all the header files if required.   */

#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

int main()
{
	ofstream outf("OUT.txt");
	char *string = "Time is a great teacher but unfortunately it kills all its pupils. Berlioz";
	outf<<string;
	return 0;
}
