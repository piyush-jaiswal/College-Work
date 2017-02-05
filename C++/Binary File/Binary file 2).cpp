/*Assuming the class Computer as follows :
class computer
{
            char chiptype[10];
            int speed;
            public:
                        void getdetails()
                        {
                                    gets(chiptype);
                                    cin>>speed;
                        }
                        void showdetails()
                        {
                                    cout << “Chip” << chiptype << “ Speed = “ << speed;
                        }
};
Write a function readfile( ) to read all the records present in an already existing binary file SHIP.DAT and display them on the screen, 
also count the number of records present in the file. */

#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

class computer
{
	

            public:
            	            char chiptype[10];
            int speed;
                        void getdetails()
                        {
                        			fflush(stdin);
                                    gets(chiptype);
                                    cin>>speed;
                        }
                        void showdetails()
                        {
                                    cout<<endl<<"Chip"<<chiptype<<"Speed = "<< speed;
                        }
};

void readfile()
{
	fstream file;
	file.open("SHIP.dat", ios::in);
	computer ob;
	int ct=0;
	
	while(file)
	{
		fflush(stdin);
		file.read((char *)&ob, sizeof(ob));
		cout<<ob.chiptype<<" "<<ob.speed;
		ct++;
		//ob.showdetails();
	}
	
	cout<<"No. of records = "<<ct<<endl;
	file.close();
}

int main()
{
	computer ob1;
	fstream file;
	file.open("SHIP.dat", ios::out | ios::app);
	if(file.fail())
		cout<<"Cannot be opened"<<endl;
	ob1.getdetails();
	file.write((char *)&ob1, sizeof(ob1));
	ob1.getdetails();
	file.write((char *)&ob1, sizeof(ob1));
	ob1.getdetails();
	file.write((char *)&ob1, sizeof(ob1));
	readfile();
	file.close();
	getch();
	return 0;
}
