#include <stdio.h>
#include "token.h"

void display(char *ch)
{
  int i;
  for (i = 0; ch[i] != '\0'; i++)
    printf("%c", ch[i]);
  printf("\n");
}

int main()
{
  char *inp = "123+65*2";
  char* x = nextToken(inp, 0);
  display(x);
}
