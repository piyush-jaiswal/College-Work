#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

//reads string.txt and returns a 2-D charcater array of the string
char** readFile()
{
  int pos = 0, i, pos2=0,count=0;
  char c, wr[20]="";
  ifstream fp;
  fp.open("string.txt");

  char **st = new char*[10];
  for(i=0; i<10; i++)
    st[i] = new char[20];

  while(!fp.eof())
  {
    fp.get(c);
    
    if(c == ' ')
    {
      wr[pos2] = '\0';
      strcpy(st[pos++], wr);
      pos2 = 0;
    }
    else
    {
      wr[pos2++] = c;
    }
  }
  return st;
}

char** lexi()
{
  int i, j;
  char temp[20];

  char **st = new char*[10];
  for(i=0; i<10; i++)
    st[i] = new char[20];

  st = readFile();

  //performing bubble sort on the array returned
  for(i=0; i<10-1; i++)
  {
    for(j=0; j<10-i-1; j++)
    {
      if(strcasecmp(st[j], st[j+1]) > 0)
      {
        strcpy(temp, st[j]);
        strcpy(st[j], st[j+1]);
        strcpy(st[j+1], temp);
      }
    }
  }

  return st;
}

//Prints the 2D character array in reverse order
void reverse(char** st)
{
  int i;

  for(i=9; i>=0; i--)
    cout << st[i] << " ";
  cout << endl;
}

