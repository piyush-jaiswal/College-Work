#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void test1()
{
	int i;
	const int NUM_HEIGHTS=3;
	int *heights=malloc(sizeof(int) * NUM_HEIGHTS);
	for(i=0;i<NUM_HEIGHTS;i++)
	{
		heights[i]=i*i;
		printf("%d %d\n",i,heights[i]);
	}
	free(heights);
}
void test2()
{
	int i;
	const int NUM_WEIGHTS=5;
	long long *weights=malloc(NUM_WEIGHTS*sizeof(*weights));
	for(i=0;i<NUM_WEIGHTS;i++)
	{
		weights[i]=100+i;
		printf("%d %lld\n",i,weights[i]);
	}
	free(weights);
}
void test3()
{
	int i;
	const int NUM_HEIGHTS=10;
	int *heights=malloc(NUM_HEIGHTS*sizeof(*heights));
	for(i=0;i<NUM_HEIGHTS;i++)
	{
		if(heights==NULL)
		{
			heights=malloc(NUM_HEIGHTS*sizeof(*heights));
		}
		
	}
	free(heights);
}

int main(int argc,char* args[])
{
	test1();
	test2();
	test3();
	return 0;
}
