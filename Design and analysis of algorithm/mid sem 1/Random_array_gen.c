#include<stdio.h>
#include<stdlib.h>

void Random_Array()
{
	int i, ar[100],r,t;
	for(i=0; i<100; i++)
		ar[i] = i+1;
	
	srand(time(NULL));
	for(i=99; i>=0; i--)
	{
		r = rand()%(i+1);
		t = ar[i];
		ar[i] = ar[r];
		ar[r] = t;
	}
	
	for(i=0; i<100; i++)
		printf("%d ", ar[i]);		
}

int main()
{
	Random_Array();
	return 0;
}
