#include<stdio.h>


int bsearch(int val, int low, int up, int *ar)
{
	int mid,f=0;

	 while(low<=up)
    {
        mid = (low+up)/2;
        if(ar[mid]==val)
        {
            f=1;
            break;
        }
        if(val>ar[mid])
            low=mid+1;
        else if(val<ar[mid])
            up=mid-1;
    }
    return f;
}


int main()
{
	int t,n,k,p,i,ct=0;
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d %d %d", &n, &k, &p);
		int ar2[k];
		for(i=0; i<k; i++)
			scanf("&d", &ar2[i]);
		int ar[n];
		for(i=0; i<n; i++)
			ar[i] = i+1;
			
		if((n-k) <p)
		{
			printf("-1\n");
			continue;
		}
		
		while(ct<p)
		{
			for(i=0; i<n; i++)
			{
				k = bsearch(ar[i], 0, k, ar2);
				
				if(!k)
					ct++;
			}
		}
		
		printf("%d\n", ar[ct]);
		ct=0;
	}
	
	return 0;
}
