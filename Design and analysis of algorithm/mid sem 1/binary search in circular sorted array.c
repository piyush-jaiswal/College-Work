#include<stdio.h>
#include<stdlib.h>

int partition(int *ar, int ln)
{
	int low=0, up=ln-1, mid;
	while(low<=up)
	{
		mid = (low+up)/2;
		if((ar[mid+1] < ar[mid]) && (ar[mid-1] < ar[mid]))
			return mid;
		if(ar[mid] > ar[0])
			low = mid+1;
		else if(ar[mid] < ar[0])
			up = mid-1;
	}
}

int bsearc(int *ar, int low, int up, int val)
{
	int mid;
	
	while(low<=up)
	{
		mid = (low+up)/2;
		if(ar[mid]==val)
		{
			printf("Found at %d\n", mid+1);
			return 1;
		}
		
		else if(ar[mid]<val)
			low = mid+1;
		else
			up = mid-1;
	}
	
	return 0;
}

int main()
{
	int ln,i,val,f;
	printf("Enter the length of the array\n");
	scanf("%d", &ln);
	int ar[ln];
	
	printf("Enter the elements\n");
	for(i=0; i<ln; i++)
		scanf("%d", &ar[i]);
	
	int p = partition(ar,ln);
	//printf("\nP = %d\n", p);
	printf("Enter the value to be searched\n");
	scanf("%d", &val);
	f = bsearc(ar, 0, p, val);
	if(f==0)
		f = bsearc(ar, p, ln-1, val);
	if(f==0)
		printf("Not found\n");
	return 0; 
}

