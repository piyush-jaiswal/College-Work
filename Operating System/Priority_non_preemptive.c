#include<stdio.h>


void arrival_sort(int* arr, int* bur, int* p, int* pr, int n)
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

			t = pr[i];
			pr[i] = pr[min];
			pr[min] =t;
		}
	}
}


void min_priority(int *arr, int *bur, int *p, int* pr, int pos2, int start_pos)
{
	int min,i,t;

	min = start_pos;
	for(i=start_pos+1; i<pos2; i++)
	{
		if(pr[i]<pr[min])
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

        t = pr[start_pos];
        pr[start_pos] = pr[min];
        pr[min] =t;
	}

}

int main()
{
	int n,i, time,pos2=0,cp;
	float awt=0.0, atrnd=0.0;
	printf("Enter the no. of processes\n");
	scanf("%d", &n);

	int arr[n], bur[n], p[n], pr[n];
	printf("Enter the arrival time of the processes\n");
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	printf("Enter the burst time of the processes\n");
	for(i=0; i<n; i++)
		scanf("%d", &bur[i]);
    printf("Enter the priority of the processes\n");
    for(i=0; i<n; i++)
        scanf("%d", &pr[i]);
	for(i=0; i<n; i++)
		p[i] = i+1;

	arrival_sort(arr,bur,p,pr,n);
	time = arr[0];
	printf("Gantt Chart:\n");
	printf("%d", time);

	while(pos2<n)
	{
		cp = pos2;
		while(arr[pos2] <= time && pos2!=n)
			pos2++;

		min_priority(arr, bur, p, pr, pos2, cp);


		awt+= time-arr[cp];
		time+= bur[cp];
		atrnd+= time - arr[cp];

		printf("\tP%d\t%d", p[cp], time);
		pos2 = cp+1;
	}


	awt/= n;
	atrnd/= n;
	printf("\nAverage Waiting Time = %f\nAverage turn-around time = %f\n", awt, atrnd);
	return 0;
}
