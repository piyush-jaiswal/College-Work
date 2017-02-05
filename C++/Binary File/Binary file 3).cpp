 /*3)	Write a function in C++, that would read contents of file STUDENT.DAT and display the details of those Students whose Percentages are above 75. */

#include<iostream>
#include<fstream>
using namespace std;
#include<conio.h>
#include<ctype.h>
#include<iomanip>
#include<stdio.h>
class Student
{
             public :
            char S_Admno[10];    //Admission number of student
            char S_Name[30];       //Name of student
            int Percentage;            //Marks Percentage of student

                        void EnterData()
                        {
                                    cout << "Enter admission number:";
                                    cin.getline(S_Admno, 10);
                                    cout<< "Enter Name :";
                                    cin.getline(S_Name, 30);
                                    cout << "Marks? ";
                                    cin>>Percentage;
                        }
                        void DisplayData()
                        {
                                    cout << setw(12) << S_Admno;
                                    cout << setw(32) << S_Name;
                                    cout <<  setw(3) << Percentage << endl;
                        }

};
int main() {
   Student s[100];
   fstream file;
   int i;

   file.open("STUDENTS.dat", ios :: out); // open file for writing
   cout << "\nWriting Student information to the file :- " << endl;
   for (i = 0; i < 3; i++)
    {
      s[i].EnterData();
      // write the object to a file
      file.write((char *)&s[i], sizeof(s[i]));
   }
   file.close(); // close the file

   file.open("STUDENTS.dat", ios :: in); // open file for reading
   cout << "\nReading Student information from the file :- " << endl;
   for (i = 0; i != '\0'; i++){
      file.read((char *)&s[i], sizeof(s[i]));
      if (s[i].Percentage >= 75)        {
            s[i].DisplayData();        }
   }
   file.close(); // close the file
    getch();
   return 0;
}

