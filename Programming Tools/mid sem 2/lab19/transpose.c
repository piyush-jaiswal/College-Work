#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

// fill the matrix with random numbers
void fill_matrix(int **mat, int n)
{
	int i, j;
	srand(time(NULL));
	
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
				mat[i][j] = rand() % 100;
}


int** get_transpose(int **mat, int n)
{
	int i,j;	
	
	int **transpose = (int**) malloc (sizeof(int*) * n);
	for(i = 0; i < n; i++)
		transpose[i] = (int*) malloc (sizeof(int) * n);
		
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
				transpose[i][j] = mat[j][i];
	
	return transpose;
}


void display(int **mat, int n)
{
	int i, j;

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
				printf("%d ", mat[i][j]);
		printf("\n");
	}
	printf("\n");
}


int main()
{
	int n, i;
	int **transpose;

	printf("Enter the size of 2-D matrix\n");
	scanf("%d", &n);
	
	int **mat = (int**) malloc (sizeof(int*) * n);
	for(i = 0; i < n; i++)
		mat[i] = (int*) malloc (sizeof(int) * n);
	
	fill_matrix(mat, n);
	transpose = get_transpose(mat, n);
	
	/*printf("\nOriginal matrix\n");
	display(mat, n);
	printf("\nTransposed matrix\n");
	display(transpose, n);*/
	
	free(mat);
	free(transpose);
	
	return 0;
}
