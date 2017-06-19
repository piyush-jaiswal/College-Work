#include <stdio.h>
#include <string.h>

int main()
{
  int ln;
  FILE *fp;
  char c, h, j, ar[100];
  
  fp = fopen("syntax.txt", "r");

  while(!feof(fp))
  {
    c = fgetc(fp);
    if(c == 'i' || c == 'I')
    {
      h = fgetc(fp);
      if(h == 'f' || h == 'F')
      {
        if(c == 'I' || h == 'F')
        {
          fgets(ar, 100, fp);
          printf("%c%c%s is invalid\n", c,h,ar);
        }
        else
        {
          j = fgetc(fp);
          if(j != '(' && j != ' ')
          {
            ungetc(j, fp);
            fgets(ar, 100, fp);
            printf("%c%c%s is invalid\n", c,h,ar);
          }
          else
          {
            fgets(ar, 100, fp);
            ln = strlen(ar);
            if(ar[ln-2] != ')')
              printf("%c%c(%s is invalid\n", c,h,ar);
            else
              printf("%c%c(%s is valid\n", c,h,ar);
          }
        }
      }
      else
        ungetc(h, fp);
    }
  }
}
