#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct node
{
	char* name;
	char* email_id;
	struct node *next;
}NODE;
NODE* START = NULL;


// Make a new node
NODE* makeNode(char *name, char *email_id)
{
	NODE* new = (NODE*) malloc (sizeof(NODE));
	new -> name = name;
	new -> email_id = email_id;
	new -> next = NULL;
	
	return new;
}


// insert node at the end
void insertNode(NODE* new)
{
	if(START == NULL)
	{
		START = new;
		return;	
	}
	
	NODE *ptr = START;
	
	while(ptr -> next != NULL)
		ptr = ptr -> next;
	ptr -> next = new;
}


// Check if c is a Character
bool isChar(char c)
{
	return (c >= 65 && c <= 90) | (c >= 97 && c <= 122);
}


// validate the name entered by the user
bool validate_name(char *name)
{
	int i;
	
	if(name[0] >= 65 && name[0] <= 90)
	{
		for(i = 1; i < strlen(name); i++)
		{
			if(!isChar(name[i]))
				return false;
		}
		return true;
	}
	
	return false;
}


// get the name entered by the user.
char* getName()
{
	char *name, is_valid = false;
	name = (char*) malloc (sizeof(char) * 20);
	
	while(!is_valid)
	{
		printf("Enter a name to be inserted in the linked list: ");
		scanf("%s", name);
		is_valid = validate_name(name);
		
		if(!is_valid)
			printf("Entered name is invalid!\n");
	}
	return name;
}


// validate the email entered by the user
bool validate_email(char *email)
{
	int i = 0, pos = 0;
	char temp[50];
	
	while(email[i] != '@')
		i++;
	
	if(i != strlen(email))
	{
		for( ; i < strlen(email); i++)
			temp[pos++] = email[i];
	}
	
	temp[pos] = '\0';
	if(!strcmp(temp, "@gmail.com"))
		return true;
	
	return false;
}


// get the email entered by the user
char* getEmail(char *name)
{
	char *email, is_valid = false;
	email = (char*) malloc (sizeof(char) * 30);
	
	while(!is_valid)
	{
		printf("Enter email-id of %s: ", name);
		scanf("%s", email);
		is_valid = validate_email(email);
		
		if(!is_valid)
			printf("Entered email-id is invalid!\n");
	}
	return email;
}


// display the current status of the list.
void displayCurrentList()
{
	if(START == NULL)
		return;
	
	NODE *ptr = START;
	
	printf("\nCurrent List: \n");
	
	while(true)
	{
		printf("Name: %s	email-id: %s ->\n", ptr -> name, ptr -> email_id);
		ptr = ptr -> next;
		
		if(ptr == NULL)
		{
			printf("Null\n\n");
			break;
		}
	}
	
}


int main()
{
	char *name, *email_id, ch1;
	
	printf("Do you want to insert a node in the list (y/n): ");
	scanf("%c", &ch1);
	
	while(true)
	{
		while(ch1 != 'y' && ch1 != 'n')
		{
			printf("Enter either y or n\n");
			printf("Do you want to insert a node in the list (y/n): ");
			scanf("%c", &ch1);
		}
		
		if(ch1 == 'n')
		{
			displayCurrentList();
			break;
		}
		
		name = getName();
		email_id = getEmail(name);
		
		NODE *new = makeNode(name, email_id);
		insertNode(new);
		
		displayCurrentList();
		
		printf("Do you want to insert a node in the list (y/n): ");
		scanf("%c", &ch1);
		scanf("%c", &ch1);
	}

	return 0;
}


