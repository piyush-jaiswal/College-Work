#include<stdio.h>



int binomial(int n, int k, int **c)
{
    if(c[n][k]!=0)
        return c[n][k];
	if(k==n || k==0)
        return 1;
    else if(k==1)
        return n;

    //int v = binomial(n-1,k-1,c) + binomial(n-1,k,c);
    //c[n][k] = v;
    return (binomial(n-1,k-1,c) + binomial(n-1,k,c));
}


int main()
{
	int n, k, ans;
	printf("Enter n and k\n");
	scanf("%d", &n);
	scanf("%d", &k);

	int **c;
	memset(c,0,sizeof(c[0][0])*(n+1)*(k+1));

	ans = binomial(n,k,c);
	printf("%dC%d = %d\n", n,k,ans);
	return 0;
}
