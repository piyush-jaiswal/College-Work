#include<stdio.h>
void initializearray(int a[], int n)
{ int i;
  for(i=0;i<n;i++)
   {a[i]=0;}
}

void Combine(int a[], int b[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        a[i]=b[i];
    }
}

int main()
{ int n,i,j,k, C, rw,max=0;
  printf("Enter the knapsack capacity\n");
  scanf("%d",&C);
  rw=C;
  printf("Enter the no. of objects\n");
  scanf("%d",&n);

  int o[n],Sel[n],temp[n];

  for(i=0;i<n;i++)
  {printf("Enter the weight/value of object %d\n",i+1);
   scanf("%d",&o[i]);
   Sel[i]=0;
   temp[i]=0;}

   for(i=0;i<n-1;i++)
      {
        for(j=i+1;j<n;j++)
         {  rw=C;
             initializearray(temp,n);
           rw= rw- o[i]- o[j];

            for(k=0;k<n;k++)
                { if(k!=i && k!=j && o[k]<=rw)
                    { rw= rw-o[k];
                      temp[k]=1;}
                }
                temp[i]=temp[j]=1;
                if(C-rw> max)
                 {max= C-rw;

                  Combine(Sel,temp,n);}
          }
       }
for(i=0;i<n;i++)
  {if(Sel[i]==1)
   {printf("\nObject %d was chosen with weight %d",i+1,o[i]);}
   }

}
