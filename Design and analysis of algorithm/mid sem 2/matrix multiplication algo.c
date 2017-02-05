#include<stdio.h>
#include<malloc.h>

int minmult(int n, int ar[], int **s)
{
	int i,j,k,diagonal,t, pos,min;
	int m[n][n];

	for(i=0; i<n; i++)
		m[i][i] = 0;

	for(diagonal=1; diagonal<n; diagonal++)
	{
		for(i=0; i<=n-diagonal-1; i++)
		{
			j = i+diagonal;
			min = m[i][i] + m[i+1][j] + ar[i]*ar[i+1]*ar[j+1];
			pos=i;
			for(k=i; k<j; k++)
			{
				t = m[i][k] + m[k+1][j] + ar[i]*ar[k+1]*ar[j+1];
				if(t<min)
				{
					min = t;
					pos = k;
				}
			}

			m[i][j] = min;
			s[i][j] = pos;
		}
	}

	return m[0][n-1];
}


void parenthasize(int **s, int low, int high)
{
	if(low==high)
		printf("A%d", low+1);
	else
    {
        printf("(");
        parenthasize(s,low,s[low][high]);
        parenthasize(s, s[low][high]+1, high);
        printf(")");
    }
}

int main()
{
	int ar[] = {20,2,30,12,8}, n=4, a,i;
	int **s = malloc(sizeof(int*) *n);

	for(i=0; i<n; i++)
		s[i] = malloc(sizeof(int*) *n);

	a = minmult(n,ar,s);
	printf("Minimum no. of multiplications = %d\n", a);

	parenthasize(s,0,n-1);
	return 0;
}
