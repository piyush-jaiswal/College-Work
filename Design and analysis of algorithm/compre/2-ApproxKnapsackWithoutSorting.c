#include<stdio.h>
int main()
{ int n,i,j,c,rw,max,sum=0;
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
   max=0;

   for(i=1;i<n;i++)
     { if(p[i]>p[max])
         {max=i;}
     }
   i=0;
   while(p[i]<rw)
   { rw=rw-p[i];
     s[i]=1;
     i++;
   }

       if(rw>0 && c-rw<p[max])
       { for(i=0;i<n;i++)
          {s[i]=0;}
          s[max]=1;
       }
   printf("Following objects were chosen");
    for(i=0;i<n;i++)
     {if(s[i]==1)
      {printf("\nobject with weight/profit %d",p[i]);
      }
      }

   }

