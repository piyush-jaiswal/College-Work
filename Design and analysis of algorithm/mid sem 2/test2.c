#include<stdio.h>

int ct;

int binomial(int n, int k, int **c)
{
    ct++;
    if(c[n][k]!=0)
        return c[n][k];
	if(k==n || k==0)
        return 1;
    else if(k==1)
        return n;

    int v = binomial(n-1,k-1,c) + binomial(n-1,k,c);
    c[n][k] = v;
    return (binomial(n-1,k-1,c) + binomial(n-1,k,c));
}


int main()
{
	int n, k, ans, i,j;
	printf("Enter n and k\n");
	scanf("%d", &n);
	scanf("%d", &k);

	int **c = malloc(sizeof(int*) *(n+1));
	for(i=0; i<n+1; i++)
        c[i] = malloc(sizeof(int*) *(k+1));

    for(i=0; i<n+1; i++)
    {
        for(j=0; j<k+1; j++)
            c[i][j] = 0;
    }
	//memset(c, 0, sizeof(c[0][0])*(n+1)*(k+1));
    ct=0;
	ans = binomial(n,k,c);
	printf("%dC%d = %d\n", n,k,ans);
	printf("Ct = %d\n", ct);
	return 0;
}
