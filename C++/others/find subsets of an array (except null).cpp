#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	int ar[] = {1,2,3,4,5};
	int len=2, i, n=5, j, k, m, pos=0, l, ct=0;
	int temp[n];
	
	while(len<=n) // conditiion for finding the subsets
	{
		for(i=0; i<n; i++) // main loop 
		{
			pos=0;
			temp[pos++] = ar[i]; // assigning temp's 1st position to value at i
			for(j=i+1; j<n; j++) // for finding the remaining nos
			{
				if(len==2 && j>i+1) // after 12,13,14,15 is printed the subset will again produce 13 which is already printed hence the condition
					continue;
				k=j;
				pos=1;
				while(pos<=len-2 && k<len) //finding elements 1 less than the desired length
					temp[pos++] = ar[k++];
				for(l=k; l<n; l++) // finding the last no
				{
					temp[pos++] = ar[l];
					if(pos==len)
					{
						for(m=0; m<len; m++) //printing
							cout<<temp[m];
						cout<<endl;
						pos=len-1;
						ct++;
					}
				}
			}
		}
		len++;
	}
	cout<<"\nct = "<<ct;
	getch();
	return 0;
}
