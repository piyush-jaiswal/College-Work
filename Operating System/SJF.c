#include<stdio.h>


void sort(int* arr, int* bur, int* p, int n)
{
	int i,j,min,t;

	for(i=0; i<n; i++)
	{
		min=i;
		for(j=i+1; j<n; j++)
		{
			if(arr[j]<arr[i])
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


int min_burst(int *arr, int *bur, int *p, int pos2, int start_pos)
{
	int min,i,t;

	min = start_pos;
	for(i=start_pos+1; i<pos2; i++)
	{
		if(bur[i]<bur[min])
			min = i;
	}

	if(min != start_pos)
	{
		t = arr[start_pos];
		arr[start_pos] = arr[min];
		arr[min] = t;

		t = bur[start_pos];
		bur[start_pos] = bur[min];
		bur[min] = t;

		t = p[start_pos];
		p[start_pos] = p[min];
		p[min] =t;
	}

	return bur[start_pos];
}


int main()
{
	int n,i, burs=0, start_time, pos2=0, cp, k; // start_time = to store the end time for the gantt chart, pos2 = to store the starting position of the remaining processes not yet executed and later for the ending pos in min _burst, cp = to store the starting pos for min_burst.

//

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

	start_time = arr[0];
	printf("\nGantt Chart");
	printf("\n%d", start_time);

	while(pos2<n)
	{
		cp = pos2;
		while(arr[pos2] <= start_time && pos2!=n)
			pos2++;

		k = min_burst(arr, bur, p, pos2, cp);

		awt+= start_time-arr[cp];
		start_time+= k;
		atrnd+= start_time - arr[cp];

		printf("\tP%d\t%d", p[cp], start_time);
		pos2 = cp+1;
	}

	awt/=n;
	atrnd/=n;

	printf("\nAverage waiting time = %f\n", awt);
	printf("\nAverage turn around time = %f\n", atrnd);
	printf("\n");
	return 0;
}




