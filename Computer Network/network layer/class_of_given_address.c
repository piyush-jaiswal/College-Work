/* write a program to find the class of a given addresss in dotted decimal notation */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	int i, num, bin, first_byte;
	char class, restOfAddress[13];	
		
	printf("Enter the address\n");
	scanf("%d.%s", &first_byte, restOfAddress);
	
	if(num>=0 && num<=127)
		class = 'A';
	else if(num>=128 && num<=191)
		class = 'B';
	else if(num>=192 && num<=223)
		class='C';
	else if(num>=224 && num<=239)
		class = 'D';
	else if(num>=240 && num<=255)
		class = 'E';
		
	printf("Class = %c\n", class);
}
