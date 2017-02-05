#include<stdio.h>
int main()
{ int n,i,j,c,rw,temp;
                                                                                                                                                                                                                                                                                                                                                         ;
  printf("Enter the no. of objects\n");
  scanf("%d",&n);
  printf("Enter the knapsack capacity\n");
  scanf("%d",&c);
  int p[n],s[n];

  for(i=0;i<n;i++)
  { printf("Enter the weight/profit of object %d-", i+1);
    scanf("%d",&p[i]);
    s[i]=0;
    }
   rw=c;

   for(i=0;i<n;i++)
     {for(j=0;j<n;j++)
       { if(p[i]>p[j])
          { temp=p[i];
             p[i]=p[j];
             p[j]=temp;
          }

       }
     }
   for(i=0;i<n;i++)
   { if(p[i]<=rw)
     {s[i]=1;
       rw=rw-p[i];
       }
     else{if(p[i]>rw && rw==0)
          {break;}
          }

   }
   printf("Following objects were chosen");
    for(i=0;i<n;i++)
     {if(s[i]==1)
      {printf("\nobject with weight/profit %d",p[i]);
      }
      }

   }

