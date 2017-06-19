#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void fillArrayRowMajor(int **mat, int row, int column)
{
	int i, j;
	
	for(i = 0; i < row; i++)
		for(j = 0; j < column; j++)
				mat[i][j] = i + j;
}


void fillArrayColumnMajor(int **mat, int row, int column)
{
	int i, j;
	
	for(i = 0; i < column; i++)
		for(j = 0; j < row; j++)
				mat[j][i] = i + j;
}


int main(int argc, char *argv[])
{
	int row, column, ch, i;
	
	ch = atoi(argv[1]);
	row = atoi(argv[2]);
	column = atoi(argv[3]);
	/*printf("Enter 0 for row major\n");
	printf("Enter 1 for column major\n");
	printf("Enter the choice, rows and columns\n");
	scanf("%d %d", &ch, &row, &column);*/
	
	int **array = (int**) malloc (sizeof(int*) * row);
	for(i = 0; i < row; i++)
		array[i] = (int*) malloc(sizeof(int) * column);
	
	if(!ch)
		fillArrayRowMajor(array, row, column);
	else
		fillArrayColumnMajor(array, row, column);
	
	// free the memory
	for(i = 0; i < row; i++)
		free(array[i]);
	free(array);
	
	return 0;
}
