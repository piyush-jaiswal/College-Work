#include<stdio.h>


void arrival_sort(int* arr, int* bur, int* p, int n) // sort according to arrival time
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


void burs_sort( int* arr, int* bur, int* p, int pos2, int start_pos) // sorting according to burst time
{
	int i,j,min,t;

	for(i=start_pos; i<pos2; i++)
	{
		min=i;
		for(j=i+1; j<pos2; j++)
		{
			if(bur[j]<bur[i])
				min=j;
		}

		if(min!=i)
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
	int n,i,start_time, pos2=0, cp, cp2, k; // start_time = to store the end time for the gantt chart, pos2 = to store the ending position of
//	the remaining processes according to arrival time, cp = to store the starting pos for remaining process; cp2 = to store the left side time of
//  the gantt chart.

	float awt=0.0, atrnd=0.0;
	printf("Enter the no. of processes\n");
	scanf("%d", &n);

	int arr[n], bur[n], p[n], arr_dyn[n]; // arr_dyn = stores the waiting time for the processes when they are preempted.
	printf("Enter the arrival time of the processes\n");
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	printf("Enter the burst time of the processes\n");
	for(i=0; i<n; i++)
		scanf("%d", &bur[i]);
	for(i=0; i<n; i++)
		p[i] = i+1;
    for(i=0; i<n; i++)
		arr_dyn[i] = arr[i];

	arrival_sort(arr,bur,p,n);

	start_time = arr[0];
	printf("\nGantt Chart");
	printf("\n%d", start_time);

	while(bur[n-1]!=0)
	{
		cp = pos2;
		while(arr[pos2] <= start_time && pos2!=n) // finding the arrived processes
			pos2++;

		burs_sort( arr,  bur,  p, pos2, cp);

		cp2 = start_time;
		if((cp2+bur[cp]) < arr[pos2] || start_time>arr[n-1] ) // calculating start_time if the burst is less than the next process' arrival
			start_time +=  bur[cp];

		else
			start_time = arr[pos2];

		bur[cp] = bur[cp] - (start_time - cp2);
        printf("\tP%d\t%d", p[cp], start_time);

        k = p[cp]-1;
        awt+= cp2 - arr_dyn[k];
        arr_dyn[k] = start_time; // changing the arrival time in arr_dyn

		if(bur[cp]<=0) // if process complete put it on the top and increment cp by 1.
        {
			pos2 = cp+1;
			atrnd += start_time - arr[cp];
        }
        else
            pos2 = cp;
	}

    atrnd/=n;
    awt/=n;
    printf("\nAverage turn around time = %f\n", atrnd);
    printf("Average waiting time = %f\n", awt);
	return 0;
}


