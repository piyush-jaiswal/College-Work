#include<stdio.h>
#include<malloc.h>


struct vertice
{
    int v;
    int wt;
};


//heap start
int heap_size;

int left(int x)
{
	return (2*x+1);
}


int right(int x)
{
	return (2*x+2);
}


swap(struct vertice ar[], int a, int lar)
{
	struct vertice t;
	t = ar[a];
	ar[a] = ar[lar];
	ar[lar] = t;
}


min_heapify(struct vertice ar[], int x)
{
	int l,r,smallest=x,t;
	l = left(x);
	r = right(x);

	if(l<heap_size && ar[l].wt < ar[x].wt)
		smallest = l;
	if(r<heap_size && ar[r].wt < ar[smallest].wt)
		smallest = r;

	if(x!=smallest)
    {
        swap(ar,x,smallest);
        min_heapify(ar, smallest);
    }
}


min_buildheap(struct vertice ar[])
{
	int n = heap_size, i;
	for(i = n/2; i>=0; i--)
		min_heapify(ar, i);
}
//heap end


int extractMin(struct vertice ar[]) // extracts the minimum weighted vertice.
{
	int n = ar[0].v;
	swap(ar, 0, heap_size-1);
	heap_size--;
	return n;
}


void display(int *ar, int n, int s) // displays the d values
{
	int i;
	printf("\n\nDistance from source to all vertices\n");
	for(i=0; i<n; i++)
		printf("%d-%d = %d\n", s,i,ar[i]);
}


int Ssearch(int *ar, int v, int end) // checks if S has v or not
{
	int i;
	for(i=0; i<end; i++)
	{
		if(ar[i]==v)
			return 1;
	}
	return 0;
}


int Qsearch(struct vertice ar[], int x, int n) // finds position of vertice x in Q
{
    int i;
    for(i=0; i<n; i++)
    {
        if(ar[i].v == x)
            return i;
    }
}


void Dijkstra(int **G, int s, int n) // performs Dijkstra's algorithm
{
	int i, u, v, pos=0, pos2;
	int d[n];
	for(i=0; i<n; i++)
		d[i] = 99999999;
	d[s] = 0;

	struct vertice Q[n];

	for(i=0; i<n; i++)
    {
        Q[i].v = i;
        Q[i].wt = d[i];
    }

	int S[n];

	heap_size = n;
	min_buildheap(Q);

	while(heap_size>0)
	{
	    min_heapify(Q,0);
		u  = extractMin(Q);
       // printf("u = %d\n", u);

		for(v=0; v<n; v++)
		{
			if(G[u][v]!= -99999 && !Ssearch(S,v,pos))
			{
                //printf("inside if\n");
				if(d[v] > d[u] + G[u][v]) // relaxation step
                {
					d[v] = d[u] + G[u][v];

					pos2 = Qsearch(Q,v,n);
					Q[pos2].wt = d[u] + G[u][v];
					//printf("inside second if\n");
                }
			}
		}
        S[pos++] = u;
	}

	display(d, n, s);
}


int main()
{
	int n,i,j,s;
	printf("Enter the no. of vertices\n");
	scanf("%d", &n);

	int **G = malloc(sizeof(int*) *n);
	for(i=0; i<n; i++)
		G[i] = malloc(sizeof(int*) *n);

	printf("Enter the values in adjacency matrix\n");
	printf("Enter the weight for an edge\n");
	printf("Enter -99999 for no edge\n");

	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(i==j)
				G[i][j] = -99999;
			else
			{
				printf("%d-%d\n", i,j);
				scanf("%d", &G[i][j]);
			}
		}
	}


	printf("Enter the source vertex\n");
	scanf("%d", &s);
	Dijkstra(G,s,n);

	return 0;
}

