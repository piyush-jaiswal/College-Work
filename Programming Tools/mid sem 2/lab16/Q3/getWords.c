#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"


// check if word ends with ing
bool checkIng(char *word, int length)
{
  if (length > 4)
    if(word[length - 4] == 'i' && word[length - 3] == 'n' && word[length - 2] == 'g')
      return true;
	return false;
}


// check if word is present in array, if present return postiion else return -1
int checkIfWordPresent (ingsAndOccurences **wordIngs, int length, char *word)
{
  int i;
  char *wordInArray;
  
  for (i = 0; i < length; i++)
  {
  	wordInArray = wordIngs[i] -> word;
    if(!strcmp (wordInArray, word))
      return i;
  }
  return -1;
}


// creates new word that ends with Ins
ingsAndOccurences* createWordIng (char *word, int occurence)
{
  ingsAndOccurences* x = (ingsAndOccurences *) malloc (sizeof(ingsAndOccurences));
  strcpy(x -> word, word);
  x -> occurences = occurence;
  return x;
}


ingsAndOccurences** findWords()
{
  int wordIngsPos = 0, i, ifPresent, wordPos = 0;
  char c, *word;   
  FILE *fp;
    
  // Creating array of structures to store words
  ingsAndOccurences **wordIngs = (ingsAndOccurences**) malloc (sizeof(ingsAndOccurences*) * 200);

  word = (char *) malloc (sizeof(char) * 30);
  fp = fopen("input.txt", "r");
  
  while(!feof(fp))
  {
    c = getc(fp);
    
    if (c == ' ' || c == '.')
    {
      if(wordPos == 0)
        continue;
      word[wordPos++] = '\0';
      
      if(checkIng(word, wordPos))
      {
        ifPresent = checkIfWordPresent (wordIngs, wordIngsPos, word);
        if(ifPresent == -1) 
          wordIngs[wordIngsPos++] = createWordIng(word, 1);    
        else
          wordIngs[ifPresent] -> occurences++;
      }
      wordPos = 0;
    }
    
    // if c is a alphabet or any other character
    else
    {
      word[wordPos++] = c;
    }
  }
  
  wordIngs[wordIngsPos] = createWordIng("THE_END", -1);
  fclose(fp);
  free(word);
  return wordIngs;
}