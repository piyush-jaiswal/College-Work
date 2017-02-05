#include<stdio.h>
#include<malloc.h>


display(int* d, int n, int s)
{
	printf("Shortest paths\n\n");
	int i;
	for(i=0; i<n; i++)
		printf("%d-%d = %d\n", s,i,d[i]);
}


bellmanFord(int** adj, int** wt, int n, int s) // runs Bellman Ford
{
	int i,u,k,v;
	int* d = malloc(sizeof(int*) *n);
	
	for(i=0; i<n; i++)
		d[i] = 99999;
	d[s] = 0;
	
	for(i=0; i<n-1; i++)
	{
		for(u=0; u<n; u++)
		{
			for(k=0; adj[u][k]!=-1 && k<n; k++)
			{
				v = adj[u][k];
				if(d[v] > d[u] + wt[u][v]) // relax operation
				{
					d[v] = d[u] + wt[u][v];
				}
			}
		}
	}
	
	
	
	for(u=0; u<n; u++) // checking for negative edge cycles
		{
			for(k=0; adj[u][k]!=-1 && k<n; k++)
			{
				v = adj[u][k];
				if(d[v] > d[u] + wt[u][v]) 
				{
					printf("Negative edge cycle detected. No solution\n");
					return;
				}
			}
		}
		
	display(d,n,s); 
}


int main()
{
	int n,i,j,v1=0,v2,w,pos1=0,pos2=0,s, ch;
	printf("Enter the no. of vertices\n");
	scanf("%d", &n);
	printf("Enter 1 for undirected or 0 for directed\n");
	scanf("%d", &ch);
	
	int** adj = malloc(sizeof(int*) *n); // adjacency list
	for(i=0; i<n; i++)
		adj[i] = malloc(sizeof(int) *n);
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			adj[i][j] = -1;
		}
	}
	
	
	int **wt = malloc(sizeof(int*) *n); // weight matrix
	for(i=0; i<n; i++)
		wt[i] = malloc(sizeof(int*) *n);
		
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			wt[i][j] = -99999;
		}
	}
	
	printf("Enter -1 in vertex 1 to exit\n"); // Inputting the edges
	while(v1!=-1)
	{
		printf("Vertex 1\n"); 
		scanf("%d", &v1);
		if(v1==-1)
			break;
			
		printf("Vertex 2\n");
		scanf("%d", &v2);
		printf("Weight\n");
		scanf("%d", &w);
		
		pos1=0;
		pos2=0;
		while(adj[v1][pos1]!=-1)
			pos1++;
		while(adj[v2][pos2]!=-1)
			pos2++;
		
		if(ch)
		{
			adj[v1][pos1] = v2;
			adj[v2][pos2] = v1;
			wt[v1][v2] = w;
			wt[v2][v1] = w;
		}
		
		else
		{
			adj[v1][pos1] = v2;
			wt[v1][v2] = w;
		}
	}
	
	printf("\n\nEnter the source vertex\n");
	scanf("%d", &s);
	
	
	bellmanFord(adj, wt, n, s);
	return 0;
	
}


