/* write a program to find first and the last address in a block given any addresses in the block and assuming classless addressing. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


int dec_to_bin(int x)
{
	int bin=0, pv=1, d;
	while(x>0)
	{
		d = x%2;
		x/=2;
		bin = bin + d*pv;
		pv*=10;
	}
	return bin;
}


int bin_to_dec(int x)
{
	int p=1, dec=0, d;
	while(x>0)
	{
		d = x%10;
		x/=10;
		dec = dec + d*p;
		p*=2;
	}
	return dec;
}


char* applyNot(char x[])
{
	for(int i=0; x[i]!='\0'; i++)
	{
		if(x[i] == '1')
			x[i] = '0';
		else
			x[i] = '1';
	}
	return x;
}


int main()
{
	int byte1, byte2, byte3, byte4, prefix, i, ib1, ib2, ib3, ib4, nib1, nib2, nib3, nib4, fbyte1, fbyte2, fbyte3, fbyte4;
	char mask[33], b1[9], b2[9], b3[9], b4[9];
	char *nb1, *nb2, *nb3, *nb4;
	nb1 = (char*)malloc(9*sizeof(char));
	nb2 = (char*)malloc(9*sizeof(char));
	nb3 = (char*)malloc(9*sizeof(char));
	nb4 = (char*)malloc(9*sizeof(char));

	printf("Do your thing!\n");
	scanf("%d.%d.%d.%d/%d", &byte1, &byte2, &byte3, &byte4, &prefix);

	//Genarating mask
	for(i=0; i<prefix; i++)
		mask[i] = '1';
	for(; i<32; i++)
		mask[i] = '0';
	mask[i] = '\0';

	//Storing mask by byte
	for(i=0; i<8; i++)
	{
		b1[i] = mask[i];
		b2[i] = mask[i+8];
		b3[i] = mask[i+16];
		b4[i] = mask[i+24];
	}
	b1[i] = '\0';
	b2[i] = '\0';
	b3[i] = '\0';
	b4[i] = '\0';

	//Converting b1 to integer
	ib1 = atoi(b1);
	ib2 = atoi(b2);
	ib3 = atoi(b3);
	ib4 = atoi(b4);

	//Applying not to each byte of mask
	nb1 = applyNot(b1);
	nb2 = applyNot(b2);
	nb3 = applyNot(b3);
	nb4 = applyNot(b4);

	//Converting the not of the mask to integer
	nib1 = atoi(nb1);
	nib2 = atoi(nb2);
	nib3 = atoi(nb3);
	nib4 = atoi(nb4);

	//Converting binary to decimal to perform biwise operations easily
	ib1 = bin_to_dec(ib1);
	ib2 = bin_to_dec(ib2);
	ib3 = bin_to_dec(ib3);
	ib4 = bin_to_dec(ib4);

	//Finding the first address
	fbyte1 = ib1 & byte1;
	fbyte2 = ib2 & byte2;
	fbyte3 = ib3 & byte3;
	fbyte4 = ib4 & byte4;

	printf("\nFirst address:\n");
	printf("%d.%d.%d.%d\n", fbyte1, fbyte2, fbyte3, fbyte4);

	//Converting binary of the not of mask to decimal to perform bitwise operations easily
	nib1 = bin_to_dec(nib1);
	nib2 = bin_to_dec(nib2);
	nib3 = bin_to_dec(nib3);
	nib4 = bin_to_dec(nib4);

	//Finding the lsat address
	byte1 = nib1 | byte1;
	byte2 = nib2 | byte2;
	byte3 = nib3 | byte3;
	byte4 = nib4 | byte4;

	printf("\nLast address:\n");
	printf("%d.%d.%d.%d\n", byte1, byte2, byte3, byte4);
	
}