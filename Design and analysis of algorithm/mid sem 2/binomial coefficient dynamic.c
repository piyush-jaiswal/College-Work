#include<stdio.h>

int min(int a, int b)
{
	if(a<=b)
		return a;
	else
		return b;
}


int binomial(int n, int k)
{
	int i,j;
	int c[n+1][k+1];
	
	for(i=0; i<=n; i++)
	{
		for(j=0; j<=min(i,k); j++)
		{
			if(j==i || j==0)
				c[i][j] = 1;
			else
				c[i][j] = c[i-1][j-1] + c[i-1][j];
		}
	}
	
	return c[n][k];
}


int main()
{
	int n, k, ans;
	printf("Enter n and k\n");
	scanf("%d", &n);
	scanf("%d", &k);
	ans = binomial(n,k);
	printf("%dC%d = %d\n", n,k,ans);
	return 0;
}
