#include<stdio.h>
#include"union_dst_import.c"


struct edges
{
    int v1,v2,wt;
};


void merge(struct edges *list, struct edges *a, int asize, struct edges *b, int bsize)
{
    int i=0,j=0,list_pos=0;
    while(i<asize && j<bsize)
        if(a[i].wt<=b[j].wt)
    {
        list[list_pos++] = a[i];
        i++;
    }
    else
    {
        list[list_pos++] = b[j];
        j++;
    }
    if(i<asize)
    {
        while(i<asize)
            list[list_pos++] = a[i++];
    }
    else if(j<bsize)
    {
        while(j<bsize)
            list[list_pos++] = b[j++];
    }

}


mergesort(struct edges list[], int size)
{
    if(size>1)
    {
        int mid, fhsize=0, shsize=0, i;
        struct edges fh[size/2];
        struct edges sh[size-size/2];
        mid = size/2;
        for(i=0; i<mid; i++)
            fh[i] = list[i];
        fhsize=i;
        for(; i<size; i++)
            sh[i-mid] = list[i];
        shsize = size-mid;
        mergesort(fh,fhsize);
        mergesort(sh,shsize);
        merge(list,fh,fhsize,sh,shsize);

    }
}


struct edges **Kruskal(struct edges E[], int no_of_edges, int n) // performs Kruskal and returns the edges selected
{
    int i,pos=0, pos_v1, pos_v2;
    struct edges T[no_of_edges]; // matrix containing the edges
    for(i=0; i<no_of_edges; i++) // initializing the vertex
        T[i].v1 = -1;

    struct node *V[n]; // array of vertices for makeset
    for(i=0; i<n; i++)
        V[i] = makeSet(i);
    mergesort(E,no_of_edges); // sorting the edges

   // printf("before for\n");
    for(i=0; i<no_of_edges; i++) // performing union
    {
        pos_v1 = E[i].v1;
        pos_v2 = E[i].v2;
        if(findSet(V[pos_v1]) != findSet(V[pos_v2]))
        {
            //printf("v1,v2,wt = %d  %d  %d\n", E[i].v1, E[i].v2, E[i].wt);
            T[pos] = E[i];
            //printf("v1,v2,wt = %d  %d  %d\n", T[0].v1, T[0].v2, T[0].wt);
            pos++;
            unionSet(V[pos_v1], V[pos_v2]);
        }
    }
    //printf("after for\n");
    for(i=0; i<n; i++)
    {
        if(T[i].v1 == -1)
            break;
        printf("Edge : %d-%d\tWt = %d\n", T[i].v1, T[i].v2, T[i].wt);
    }
   // printf("v1,v2,wt = %d  %d  %d\n", T[0].v1, T[0].v2, T[0].wt);
    return T;
}


display(struct edges *T, int n) // display the edges selected
{
    printf("inside display\n");
    int i;
    for(i=0; i<n; i++)
    {
        if(T[i].v1 == -1)
            break;
        printf("Edge : %d-%d\tWt = %d\n", T[i].v1, T[i].v2, T[i].wt);
    }
    printf("Performed display\n");
}


int main()
{
    int n,i,j,ct=0,pos=0;
    printf("Enter the no. of vertices\n");
    scanf("%d", &n);

    int **G = malloc(sizeof(int*) *n);
    for(i=0; i<n; i++)
        G[i] = malloc(sizeof(int*) *n);

    printf("Enter the values in adjacency matrix\n");
	printf("Enter the weight for an edge\n");
	printf("Enter -99999 for no edge\n");

	for(i=0; i<n; i++) // inputting the matrix
	{
		for(j=0; j<n; j++)
		{
			if(i==j)
				G[i][j] = -99999;
			else
			{
				printf("%d-%d\n", i,j);
				scanf("%d", &G[i][j]);
				if(G[i][j]!=-99999)
                    ct++;
			}
		}
	}

	struct edges E[ct]; // for storing the edges
    for(i=0; i<n; i++) // checking for edges
	{
		for(j=0; j<n; j++)
		{
            if(G[i][j]!=-99999)
            {
                E[pos].v1 = i;
                E[pos].v2 = j;
                E[pos].wt = G[i][j];
                pos++;
            }
		}
	}
    struct edges **T;
	T = Kruskal(E,ct,n);
	printf("performed kruskal\n");
	//printf("v1,v2,wt = %d  %d  %d\n", T[0]->v1, T[0]->v2, T[0]->wt);
	//printf("v1,v2,wt = %d  %d  %d\n", T[2].v1, T[2].v2, T[2].wt);
	//display(T, ct);
	return 0;
}
