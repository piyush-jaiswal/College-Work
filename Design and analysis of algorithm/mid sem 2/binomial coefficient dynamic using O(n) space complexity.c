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
	int c1[k];
	int c2[k];

	for(i=0; i<k; i++)
        c1[i] = 1;

	for(i=1; i<=n; i++)
	{
		for(j=0; j<=min(i,k); j++)
		{
			if(j==0 || j==i)
                c2[j] = 1;
            else
                c2[j] = c1[j-1] + c1[j];
		}

		for(j=0; j<=min(i,k); j++)
            c1[j] = c2[j];
	}

	return c2[k];
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
