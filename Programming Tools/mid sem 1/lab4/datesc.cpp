#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>

using namespace std;

int date_compare(char date[], int dd, int mm, int yyyy)
{
  char d[3], m[3], y[5];

  d[0] = date[0];
  d[1] = date[1];
  d[2] = '\0';

  m[0] = date[3];
  m[1] = date[4];
  m[2] = '\0';

  y[0] = date[6];
  y[1] = date[7];
  y[2] = date[8];
  y[3] = date[9];
  y[4] = '\0';

  if(dd == atoi(d) && mm == atoi(m) && yyyy == atoi(y))
    return 1;
  return 0;
}

int date_Search(int dd, int mm, int yyyy)
{
  char ch[100], c, ch2[1000];
  int pos=0, f=0;
  ifstream inf;
  inf.open("input.txt");

  inf.get(c);
  ch[pos++] = c;

  while(!inf.eof())
  {
    if(c == ' ' || c == '\n')
    {
      ch[pos] = '\0';
      if(!strcmp(ch, "Date: "))
      {
        inf.get(ch2, 100, '\n');
        f = date_compare(ch2, dd, mm, yyyy);
        if(f)
        {
          cout << endl << "Date: " << ch2 << endl << endl;
          inf.get();
          inf.get(ch2, 1000, '\n');
          cout << ch2 << endl << endl;
          inf.get();

          inf.get(ch2, 1000, '\n');
          cout << ch2 << endl << endl;
          inf.close();
          return 1;
        }
      }
      pos = 0;
    }
    
    inf.get(c);
    ch[pos++] = c;
  } 
  
  inf.close(); 
  return 0;
}
