#include <iostream>
#include <string>

using namespace std;


class Staff
{
  string code, Name;
};


class Faculty : Staff
{
  string department, subject_taken, research_area;
};


class Typist : Staff
{
  string office;
  double speed;
};


class Officer : Staff
{
  string rank, grade;
};


class Permanent : Typist
{
  double salary;
};


class Casual : Typist
{
  double daily_wages;
};


int main()
{
  cout << "Dummy run" << endl;
  return 0;
}
