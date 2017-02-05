#include<stdio.h>

int heap_size = 10;

int parent( int x)
{
	return x/2;
}


int left(int x)
{
	return (2*x+1);
}


int right(int x)
{
	return (2*x+2);
}


swap(int* ar, int a, int lar)
{
	int t;
	t = ar[a];
	ar[a] = ar[lar];
	ar[lar] = t;
}


heapify(int* ar, int x)
{
	int l,r,largest=x,t;
	l = left(x);
	r = right(x);

	if(l<heap_size && ar[l]>ar[x])
		largest = l;
	if(r<heap_size && ar[r]>ar[largest])
		largest = r;

	swap(ar,x,largest);
	if(x!=largest)
		heapify(ar, largest);
}


buildheap(int* ar)
{
	int n = heap_size, i;
	//for(i = n/2; i>=1; i--)
	for(i = n/2; i>=0; i--)
		heapify(ar, i);
}


min_heapify(int* ar, int x)
{
	int l,r,smallest=x,t;
	l = left(x);
	r = right(x);

	if(l<heap_size && ar[l]<ar[x])
		smallest = l;
	if(r<heap_size && ar[r]<ar[smallest])
		smallest = r;

	if(x!=smallest)
    {
        swap(ar,x,smallest);
        min_heapify(ar, smallest);
    }
}


min_buildheap(int* ar)
{
	int n = heap_size, i;
	//for(i = n/2; i>=1; i--)
	for(i = n/2; i>=0; i--)
		min_heapify(ar, i);
}


heapsort(int *ar)
{
	buildheap(ar);
	int i;

	for(i= heap_size-1; i>=1; i--)
	{
		swap(ar,0, i);
		heap_size -= 1;
		heapify(ar,0);
	}
}


min_heapsort(int *ar)
{
	min_buildheap(ar);
	int i;

	for(i= heap_size-1; i>=1; i--)
	{
		swap(ar,0, i);
		heap_size --;
		min_heapify(ar,0);
	}
}


int main()
{
	int ar[] = {16,4,10,14,7,9,3,2,8,1};
	min_heapsort(ar);
	int i;
	for(i=0; i<10; i++)
		printf("%d	", ar[i]);

	return 0;
}


