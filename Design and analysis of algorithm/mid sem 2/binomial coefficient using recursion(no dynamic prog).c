#include<stdio.h>


int binomial(int n, int k)
{
	if(k==n || k==0)
        return 1;
    if(k==1)
        return n;
    return (binomial(n-1,k-1) + binomial(n-1,k));
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
