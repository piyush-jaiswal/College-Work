#include<stdio.h>


sort_arrival(int* arr, int* bur, int* prior, int* p, int n) // sort according to arrival time
{
	int i,j,min,t;
	
	for(i=0; i<n; i++)
	{
		min=i;
		for(j=i+1; j<n; j++)
		{
			if(arr[j]<arr[min])
				min = j;
		}
		
		if(min!=i)
		{
			t = arr[i];
			arr[i] = arr[min];
			arr[min] = t;
			
			t = bur[i];
			bur[i] = bur[min];
			bur[min] = t;
			
			t = prior[i];
			prior[i] = prior[min];
			prior[min] = t;
			
			t = p[i];
			p[i] = p[min];
			p[min] = t;
		}
	}	
}


min_priority(int* arr, int* bur, int* prior, int* p, int n, int start_pos, int end_pos) // finds the minimum priority process and swaps it with the top
{
	int i,min,t;
	
	min = start_pos;
	for(i=start_pos+1; i<end_pos; i++)
	{
		if(prior[i]<prior[min])
			min = i;
	}
	
	if(min!=start_pos)
	{
		t = arr[start_pos];
		arr[start_pos] = arr[min];
		arr[min] = t;
			
		t = bur[start_pos];
		bur[start_pos] = bur[min];
		bur[min] = t;
			
		t = prior[start_pos];
		prior[start_pos] = prior[min];
		prior[min] = t;
			
		t = p[start_pos];
		p[start_pos] = p[min];
		p[min] = t;
	}
}


int main()
{
	int n,i,time,pos=0,cp,cp2,k;
	float awt=0.0, atrnd=0.0;
	
	printf("Enter the no. of processes\n");
	scanf("%d", &n);
	int arr[n], bur[n], prior[n], p[n], arr_dyn[n];
	
	printf("Enter the arrival time\n"); //inputting the data
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	printf("Enter the burst time\n");
	for(i=0; i<n; i++)
		scanf("%d", &bur[i]);
	printf("Enter the priorities\n");
	for(i=0; i<n; i++)
		scanf("%d", &prior[i]);
	for(i=0; i<n; i++)
		p[i] = i+1;
	for(i=0; i<n; i++)
		arr_dyn[i] = arr[i];
		
	sort_arrival(arr,bur,prior,p,n);
	time = arr[0];
	printf("Gantt Chart:\n");
	printf("%d", arr[0]);
	
	while(pos!=n)
	{
		cp = pos;
		cp2=cp;
		while(arr[pos]<=time && pos<n)
			pos++;
		min_priority(arr,bur,prior,p,n,cp,pos);
		
		if(((time+bur[cp]) <= arr[pos]) || time>arr[n-1]) //if the burst time is less than the next arrival or if all have arrived
		{
			k = p[cp]-1;
			awt+= time-arr_dyn[k];
			time+= bur[cp];
			atrnd+= time - arr[cp];
			cp2++;
			bur[cp]-= bur[cp];
			
		} 
		
		else // if burst time more than the next arriving process
		{
			k = p[cp]-1;
			awt+= time-arr_dyn[k];
			bur[cp]-= arr[pos] - time;
			time = arr[pos];
			arr_dyn[k] = time;
		}
		
		printf("\tP%d\t%d", p[cp], time);
		pos = cp2;
	}
	
	awt/=n;
	atrnd/=n;
	printf("\n\nAverage Waiting Time = %f\n", awt);
	printf("Average turn around time = %f\n", atrnd);
	return 0;
}
