#include<iostream>

//checks whether the string has atleast 1 upper case letter
bool upperc(char* st)
{
  int pos=0;

  while(st[pos] != '\0')
  {
    if(st[pos] >= 65 && st[pos] <= 90)
      return true;
    pos++;
  }
  return false;	
}
