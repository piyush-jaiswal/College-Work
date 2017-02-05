#include<stdio.h>


void sort(int* arr, int* bur, int* p, int n)
{
	int i,j,min,t;

	for(i=0; i<n; i++)
	{
		min=i;
		for(j=i+1; j<n; j++)
		{
			if(arr[j]<arr[min])
				min=j;
		}

		if(i!=min)
		{
			t = arr[i];
			arr[i] = arr[min];
			arr[min] = t;

			t = bur[i];
			bur[i] = bur[min];
			bur[min] = t;

			t = p[i];
			p[i] = p[min];
			p[min] =t;
		}
	}
}


int main()
{
	int n,i, burs=0;
	float awt=0.0, atrnd=0.0;
	printf("Enter the no. of processes\n");
	scanf("%d", &n);

	int arr[n], bur[n], p[n];
	printf("Enter the arrival time of the processes\n");
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	printf("Enter the burst time of the processes\n");
	for(i=0; i<n; i++)
		scanf("%d", &bur[i]);
	for(i=0; i<n; i++)
		p[i] = i+1;

	sort(arr,bur,p,n);

	printf("%d\tP%d\t%d", arr[0], p[0], bur[0]);
	atrnd = bur[0] - arr[0];
	burs+= bur[0];
	for(i=1; i<n; i++)
	{
		printf("\tP%d\t%d", p[i], burs+bur[i]);
		awt+= burs - arr[i];
		burs+= bur[i];
		atrnd+= burs - arr[i];
	}

	awt/= n;
	atrnd/= n;
	printf("\nAverage Waiting Time = %f\nAverage turn-around time = %f\n", awt, atrnd);
	return 0;
}
