#include <stdio.h>
#include <stdlib.h>
#define MAX_NTH 100


long long get_nth_fibo_dprog(int n, int* results)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	// dynamic prog
	if (results[n] != -1)
		return results[n];
	
	long long ans;
	ans =  get_nth_fibo_dprog(n-1, results) + get_nth_fibo_dprog(n-2, results);
	results[n] = ans;
	return ans;
}


long long get_nth_fibo(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	
	return get_nth_fibo(n-1) + get_nth_fibo(n-2);
}


long long get_nth_fibo_loop(int n)
{
	long long n_1 = 0, n_2 = 1, temp, ans;
	int i;
	
	for(i = 2; i <= n; i++)
	{
		temp = n_2;
		n_2 += n_1;
		n_1 = temp;
	}
	
	return n_2;
}


int main(int argc, char* argv[])
{
	int nth, i, is_optimized;
	long long nth_fibo;
	
	nth = atoi(argv[1]);
	is_optimized = atoi(argv[2]);

	switch (is_optimized)
	{
		case 0:
			nth_fibo = get_nth_fibo(nth);
			break;
		
		// Curly braces had to be used because you can't declare variables inside a case statement without the braces. Has scope issues.
		case 1:
		{
			int *results = (int *) malloc (sizeof(int) * MAX_NTH);
			for (i = 0; i < MAX_NTH; i++)
				results[i] = -1;
	
			nth_fibo = get_nth_fibo_dprog(nth, results);
			free(results);
			break;
		}
			
		case 2:
			nth_fibo = get_nth_fibo_loop(nth);
	}
	
	printf("Nth fibo = %llu\n", nth_fibo);

	
	return 0;
}
