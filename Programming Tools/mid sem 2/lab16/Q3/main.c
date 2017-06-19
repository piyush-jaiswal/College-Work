#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header.h"

int main()
{
  int i = 0;
  ingsAndOccurences **x = findWords();
  wordsInFile(x);
  
  while(true)
  {
    if(x[i] -> occurences == -1)
    {
      free (x[i]);
      break;
    }
    free (x[i]);
    i++;
  }

  free(x);
  return 0;  
}
