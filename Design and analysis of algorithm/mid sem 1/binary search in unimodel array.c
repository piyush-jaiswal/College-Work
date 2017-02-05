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
		if(ar[mid+1] > ar[mid])
			low = mid+1;
		else if(ar[mid+1] < ar[mid])
			up = mid-1;
	}
}

void bsearch2(int *ar, int ln, int p, int val)
{
	int low=p,up=ln-1, mid;
	
	while(low<=up)
	{
		mid = (low+up)/2;
		if(ar[mid]==val)
		{
			printf("Found at %d\n", mid+1);
			return;
		}
		
		else if(ar[mid]<val)
			up = mid-1;
		else
			low = mid+1;
	}
	
	printf("Not found\n");
}


void bsearc(int *ar, int ln, int p, int val)
{
	int low=0, up=p, mid;
	
	while(low<=up)
	{
		mid = (low+up)/2;
		if(ar[mid]==val)
		{
			printf("Found at %d\n", mid+1);
			return;
		}
		
		else if(ar[mid]<val)
			low = mid+1;
		else
			up = mid-1;
	}
	
	bsearch2(ar, ln, p, val);
}

int main()
{
	int ln,i,val;
	printf("Enter the length of the array\n");
	scanf("%d", &ln);
	int ar[ln];
	
	printf("Enter the elements\n");
	for(i=0; i<ln; i++)
		scanf("%d", &ar[i]);
	
	int p = partition(ar,ln);
	printf("Enter the value to be searched\n");
	scanf("%d", &val);
	bsearc(ar, ln, p, val);
	return 0;
}

