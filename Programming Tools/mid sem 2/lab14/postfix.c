#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"
#include "stack.h"

int precedenceOf(char c)
{
  if(c == '(')
    return 1;
  if(c == '^')
    return 2;
  if(c == '/' || c == '*' || c == '%')
    return 3;
  if(c == '+' || c == '-')
    return 4;
}


int operate(int n1, int n2, char op)
{
  switch(op)
  {
  	case '+':
  	  return n1 + n2;
  	case '-':
  	  return n1 - n2;
    case '*':
  	  return n1 * n2;
  	case '/':
  	  return n1 / n2;
  	case '%':
  	  return n1 % n2;
  	case '^':
  	  return n1 ^ n2;
  }	
}


int evaluate(char **s, int limit)
{
  int sPos=0, i, n1, n2, ans;
  struct stack num;

  for(i = 0; i< limit; i++)
  {
    if(!isOperator(s[sPos][0]))
      pushNum(num, atoi(s[sPos++]));
    else
    {
      n1 = popNum(num);
      n2 = popNum(num);
      ans = operate(n1, n2, s[sPos][0]);
      pushNum(num, ans);
      sPos++;
    }
  }
  
  return popNum(num);
}


void postfix(char *ch)
{
  struct stack ops;
  int chPos=0, i, postfixPos=0;
  char **postfix, *x;
  postfix = (char **) malloc (sizeof(char*) * 20);
  for(i = 0; i < 20; i++)
    postfix[i] = (char*) malloc (sizeof(char) * 100);

  while(ch[chPos] != '\0')
  {
    x = nextToken(ch, chPos);
    chPos = chPos + strlen(x);
    
    if(x[0] == ')')
    {
      while(pop(ops) != '(')
      	postfix[postfixPos++] = (char*)pop(ops);
    }
   
    else if(isOperator(x))
    {
      if(isEmpty(ops))
        push(ops, x[0]);
      else
      {
        if(precedenceOf(x[0]) > precedenceOf(peek(ops)))
        {
    	  while(precedenceOf(peek(ops)) > precedenceOf(x[0]) && !isEmpty(ops))
           postfix[postfixPos++] = (char*)pop(ops);
        }
        push(ops, x[0]);
      }
    }
    
    else
    {
      postfix[postfixPos++] = x;
    }
  }
  
  while(!isEmpty(ops))
  {
    postfix[postfixPos++] = (char*)pop(ops);
  }

  evaluate(postfix, 20);
}
