#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main()
{
	char string[100], ch;
	int asc, i=1;
	bool not_valid = false;
	
	printf("Enter the string\n");
	gets(string);

	ch = string[0];
	asc = (int) ch;

	if(ch=='_' || (asc>=65 && asc<=90) || (asc>=97 && asc<=122))
	{
		while(string[i]!='\0')
		{
			ch = string[i];
			asc = (int)ch;
			
			if(ch=='_' || (asc>=65 && asc<=90) || (asc>=97 && asc<=122) || (asc>=48 && asc<=57))
			{
				i++;
				continue;
			}
			
			else	
			{
				not_valid = true;
				break;
			}
		}
	}

	else
		not_valid = true;

	if(not_valid==true)
		printf("Not a valid identifier\n");
	else
		printf("Valid identifier\n");

	return 0;
}
