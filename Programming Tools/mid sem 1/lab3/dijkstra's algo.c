#include<stdio.h>
#define N 5

int contains(int sptset[], int v, int n)
{
  int i;
  for(i=0; i<n; i++)
  {
    if(sptset[i] == v)
      return 1;
  }
  return 0;
}

int Dijkstra(int M[][N], int s, int d)
{
  int Distance[N], sptset[N], i, pos=0, min, minpos, dist;
  
  for(i=0; i<N; i++)
    Distance[i] = 9999;
  Distance[s] = 0;

  while(pos != N)
  {
  
    if(contains(sptset, d, pos))
      break;

    //Find the minimum vertex
    min = 999;
    minpos = N+1;
    for(i=0; i<N; i++)
    {
      if(!contains(sptset, i, pos))
      {
        //printf("yes\n");
        if(Distance[i] < min)
        {
          //printf("yes yes\n");
          min = Distance[i];
          minpos = i;
        }
      }
      //printf("minpos = %d\t min = %d\n", minpos, min); 
    }

	//printf("minpos = %d\t min = %d\n", minpos, min); 
    sptset[pos++] = minpos;
    //Updating distance of neighbours
    for(i=0; i<N; i++)
    {
      dist = M[minpos][i];
      if(dist != 0)
      {
        if(Distance[minpos]+dist < Distance[i])
          Distance[i] = Distance[minpos] + dist;
      }
    }
    
    /*for(i=0; i<N; i++)
    	printf("%d  ", Distance[i]);
    printf("\n"); */
  }
  
  return Distance[d];
}


int main()
{
  int i, j, s, d, distance; 

  int M[N][N] = {
                 {0, 10, 0, 5, 0},
                 {0, 0, 1, 2, 0},
                 {0, 0, 0, 0, 4},
                 {0, 3, 9, 0, 2},
                 {7, 0, 6, 0, 0}
                };

 /* printf("Enter the matrix\n");
    printf("Enter 0 for no edge\n");
  for(i=0; i<N; i;++)
  {
    printf("For vertex %d\n", i);
    for(j=0; j<N; j++)
      scanf("%d", &M[i][j]);
  }*/
  printf("Enter the source and destination\n");
  scanf("%d %d", &s, &d);

  distance = Dijkstra(M, s, d);
  printf("Distance = %d\n", distance);
  
  return 0;
}
