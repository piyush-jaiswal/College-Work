#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isOperator(char c)
{
  if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^' || c == '(')
    return true;
  return false;
}

char* nextToken(char* inp, int inpPos)
{
  int chPos = 0;
  char *ch, c;
  ch =  (char*) malloc (sizeof(char) * 10);  
  c = inp[inpPos++];
  ch[chPos++] = c;
  if(isOperator(c))
  {
    ch[chPos++] = '\0';
    return ch;
  }
  
  else
  {
    c = inp[inpPos++];
    while(!isOperator(c) && inp[inpPos] != '\0')
    {
       ch[chPos++] = c;
       c = inp[inpPos++];
    }
  ch[chPos] = '\0';
  return ch;
  }
}
