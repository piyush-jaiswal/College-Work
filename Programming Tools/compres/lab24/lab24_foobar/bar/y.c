#include <stdio.h>
#include <time.h>
#define NUM_RANGE 10000


int reverse(int n)
{
	int rev = 0;
	
	while(n > 0)
	{
		rev = rev * 10 + n % 10;
		n /= 10;
	}
	return rev;
}


int main()
{
	int n, reversed;
	
	srand(time(NULL));
	n = rand() % NUM_RANGE;
	reversed = reverse(n);
	
	printf("No. genarated = %d\n", n);
	printf("Reverse = %d\n", reversed);
	
	return 0;
}
