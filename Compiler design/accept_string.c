//Write a C program to recognize strings under 'a*', 'a*b+', 'abb'.

#include<stdio.h>
#include<string.h>

int stateTransition(int state, int input) //state transition function
{
	switch(state)
	{
		case 0:
			if(input=='a')
				state = 1;
			else
				state = 7;
			break;
		
		case 1:
			if(input=='a')
				state = 4;
			else
				state = 2;
			break;
		
		case 2:
			if(input=='a')
				state = 6;
			else
				state = 3;
			break;

		case 3:
			if(input=='a')
				state = 6;
			else
				state = 5;
			break;
		
		case 4:
			if(input=='a')
				state = 4;
			else
				state = 5;
			break;

		case 5:
			if(input=='a')
				state = 6;
			else
				state = 5;
			break;
		
		case 6:
			if(input=='a')
				state = 6;
			else
				state = 6;
			break;
		
		case 7:
			if(input=='a')
				state = 6;
			else
				state = 7;
			break;

		default:
			state = -1;
	}
	return state;
}

int main()
{
	int current_state=0,i=0;
	char string[100];

	printf("Enter the string\n");
	gets(string);

	while(string[i]!='\0')
	{
		current_state = stateTransition(current_state,string[i]);
		i++;
	}
	
	if(current_state == 0 || current_state == 1 || current_state == 4)
		printf("String accepted under a*\n");
	else if(current_state == 2 || current_state == 5 || current_state == 7)
		printf("String accepted under a*b+\n");
	else if(current_state == 3)
		printf("String accepted under abb\n");
	else
		printf("String not accepted\n");

	return 0;
	
}
