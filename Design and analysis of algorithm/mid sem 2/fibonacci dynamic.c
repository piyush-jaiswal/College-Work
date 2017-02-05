#include<stdio.h>


int fibDyn(int n, int *f)
{
	int a;
	
	if(n<=1)
		return n;
		
	if(f[n]!=0)
		return f[n];
	
	else
	{
		a = fibDyn(n-1,f) + fibDyn(n-2,f);
		f[n] = a;
		return a;
	}
}


int main()
{
	int n, ans, i;
	printf("Enter the nth fibonacci no. to be found\n");
	scanf("%d", &n);
	int f[n+1];
	
	for(i=0; i<n+1; i++)
		f[i] = 0;
		
	ans = fibDyn(n,f);
	printf("Fibonacci of %d = %d\n", n, ans);
	return 0;
}
