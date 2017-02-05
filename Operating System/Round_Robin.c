#include<stdio.h>


void min_rqueue(int *rqueue, int *bur, int *p, int n, int start_pos) // finds the minimum value and swaps it with the first position of the array.
{
	int min,i,t;

	min = start_pos;
	for(i=start_pos+1; i<n; i++)
	{
		if(rqueue[i]<rqueue[min])
			min = i;
	}

	if(min != start_pos)
	{
		t = rqueue[start_pos];
		rqueue[start_pos] = rqueue[min];
		rqueue[min] = t;

		t = bur[start_pos];
		bur[start_pos] = bur[min];
		bur[min] = t;

		t = p[start_pos];
		p[start_pos] = p[min];
		p[min] =t;
	}

}


int main()
{
	int n,i, ts, time, pos=0, k;

	float awt=0.0, atrnd=0.0;
	printf("Enter the no. of processes\n");
	scanf("%d", &n);

	int arr[n], bur[n], p[n],bur2[n];
	printf("Enter the arrival time of the processes\n");
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	printf("Enter the burst time of the processes\n");
	for(i=0; i<n; i++)
		scanf("%d", &bur[i]);
	for(i=0; i<n; i++)
		p[i] = i+1;
	printf("Enter the time slice\n");
		scanf("%d", &ts);
	for(i=0; i<n; i++) // making a copy of burst to calculate awt
		bur2[i] = bur[i];

	int rqueue[n];
	for(i=0; i<n; i++) // at first the arrival time will go in the queue. Then the time at which they enter the ready queue according to the time slice.
		rqueue[i] = arr[i];
	min_rqueue(rqueue, p, bur, n, pos);
	time = rqueue[0];
	printf("\nGantt Chart\n");
	printf("%d", rqueue[0]);

	while(pos!=n)
	{
		if(bur[pos] < ts)
		{
			time+= bur[pos];
			printf("\tP%d\t%d", p[pos], time);
			k = p[pos]-1; // k is the position in which the burst time, arr time etc for the process p[pos] is stored.
			awt+= time - bur2[k] - arr[k];
			atrnd+= time - arr[k];
			pos++;
		}
		else
		{
			time+= ts;
			bur[pos]-= ts;
			rqueue[pos] = time;
			printf("\tP%d\t%d", p[pos], time);
		}

		min_rqueue(rqueue, p, bur, n ,pos);
	}

	awt/=n;
	atrnd/=n;
	printf("\n\nAverage waiting time = %f\n", awt);
	printf("Average turn around time = %f\n", atrnd);
	return 0;
}
