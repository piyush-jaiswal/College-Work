/* 1) Assuming the class EMPLOYEE given below, write functions in C++ to perform following:
(i) Write the objects of EMPLOYEE to a binary file.
(ii) Read the objects of EMPLOYEE from binary file and display them on screen. */

#include<iostream>
#include<fstream>
#include<conio.h>

using namespace std;

class EMPLOYEE
{
            int ENO;
            char ENAME[10];
            public :
            void GETIT()
            {
                        cin >> ENO;
                        fflush(stdin);
                        gets (ENAME);
            }
            void SHOWIT()
           {
                        cout <<ENO <<endl<< ENAME <<endl;
            }
}; 

int main()
{
	fstream file;
	file.open("employee.dat", ios::out | ios::binary);
	if(file.fail())
		cout<<"Load error"<<endl;
	EMPLOYEE ob;
	ob.GETIT();
	file.write((char *)&ob, sizeof(ob));
	file.close();
	file.open("employee.dat", ios::in);
	EMPLOYEE ob2;
	file.read((char *)&ob2, sizeof(ob2));
	ob2.SHOWIT();
	getch();
	return 0;
}    
