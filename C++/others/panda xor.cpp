#include<iostream>
#include<math.h>
using namespace std;

int freq[127];

int length(int n)
{
	int ct=0;
	while(n>0)
	{
		n=n/10;
		ct++;
	}
	return ct;
}

int dectobin(int x)
{
	int pv=1, bin=0;
	while(x>0)
	{
		bin = bin+x%2*pv;
		x/=2;
		pv*=10;
	}
	return bin;
}

int bintodec(int x)
{
	int power=0, dec=0;
	while(x>0)
	{
		dec = dec+ x%10*(int)pow(2,power);
		x/=10;
		power++;
	}
	return dec;
}

void maxor(int *temp, int n)
{
	int bin[n], i, maxlen=0, pv=1, num=0, orans, d;
	for(i=0; i<n; i++)
	{
		bin[i] = dectobin(temp[i]);
		if(length(bin[i]) > maxlen)
			maxlen = length(bin[i]);
	}
	
	while(maxlen>0)
	{
		orans=0;
		for(i=0; i<n; i++)
		{
			if(bin[i]>=0)
			{
				d = bin[i]%10;
				bin[i]/=10;
				if(d==orans)
					orans=0;
				else
					orans = 1;
			}
		}
		num = orans*pv + num;
		pv*=10;
		maxlen--;
	}
	d = bintodec(num);
	freq[d]%= 1000000007;
	freq[d]++;
}

void findsub(int *ar, int n)
{
	int i, len=2, j, k, m, pos=0, l;
	for(i=0; i<127; i++)
		freq[i]=0;
	for(i=0; i<n; i++)
		freq[ar[i]]++;
	
	int temp[n];
	
	while(len<=n) // condition for finding the subsets
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
						maxor(temp, len);
						pos=len-1;
					}
				}
			}
		}
		len++;
	}
}



int main()
{
	int n,i,sel=0;
	cin>>n;
	int ar[n];
	for(i=0; i<n; i++) // inputting elements
		cin>>ar[i];
	findsub(ar, n);
	for(i=0; i<127; i++)
	{
		if(freq[i]>=2)
		{
			sel%= 1000000007;
			sel++;
		}
	}
	cout<<sel;
}
