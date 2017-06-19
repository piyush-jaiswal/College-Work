#include <stdio.h>
#include <stdlib.h>

// swapping the memory address instead of values
void swap(int **x, int **y)
{
  int *swap;
  swap = *x;
  *x = *y;
  *y = swap;  
}


void display(int *x, int* y)
{
  printf("x = %d\n", *x);
  printf("y = %d\n", *y);
}


int main()
{
  int *x, *y;
  x = (int *) malloc (sizeof(int));
  y = (int *) malloc (sizeof(int));

  printf("Enter the nos\n");
  scanf("%d %d", x, y);
 
  printf("Values before swapping\n");
  display(x, y);
  
  swap(&x, &y);

  printf("Values after swapping\n");
  display(x, y);

  free(x);
  free(y);  

  return 0;
}
