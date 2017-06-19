#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>

using namespace std;

int date_Search(int, int, int);

int word_Search(char s[])
{
  char c, date[100], ch[100], d[3], m[3], y[5];
  int pos=0, f=0;
  
  ifstream inf;
  inf.open("input.txt");
  
  inf.get(c);
  ch[pos++] = c;
  
  while(!inf.eof())
  {
    if(c == ' ' || c == '\n')
    {
      ch[pos-1] = '\0'; //pos-1 to omit space character
      if(!strcmp(ch, "Date:"))
      {
        inf.get(date, 100, '\n');

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

        if(!strcmp(s, d) || !strcmp(s, m) || !strcmp(s, y))
        {
          date_Search(atoi(d), atoi(m), atoi(y));

          inf.get();
          inf.get(ch, 1000, '\n');
          inf.get();
          inf.get(ch, 1000, '\n');
          inf.get();
        }
      }
      
      else if(!strcmp(ch, s))
      { 
        date_Search(atoi(d), atoi(m), atoi(y));
        f = 1;
      }
      pos = 0;
    }
    
      inf.get(c);
      ch[pos++] = c;
    }
    
    inf.close();
    return f;
}
