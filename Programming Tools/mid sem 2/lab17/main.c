#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "Node.h"


int main()
{
	int ch = 2, val;
	Node *Start = NULL, *new, *current, *before;
	
	while(ch != -1)
	{
		printf("\n\n**************************************************\n");
		printf("Enter 1 to insert at beginning\n");	
		printf("Enter 2 to insert at end\n");
		printf("Enter 3 to delete at beginning\n");		
		printf("Enter 4 to delete at end\n");
		printf("Enter 5 to traverse\n");
		printf("Enter -1 to end\n");
		printf("Enter your choice\n");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1:
				printf("\nEnter the value of node\n");
				scanf("%d", &val);
				new = newNode(val);
				Start = insertAtBeg(Start, new);
				break;
			
			case 2:
				printf("\nEnter the value of node\n");
				scanf("%d", &val);
				new = newNode(val);
				Start = insertAtEnd(Start, new);
				break;
				
			case 3:
				Start = deleteAtBeg(Start);
				break;
			
			case 4:
				Start = deleteAtEnd(Start);
				break;
			
			case 5:
				traverse(Start);
				break;
			
			case -1:
				break;
		}
	}
	
	current = Start;
	while (current != NULL)
	{
		before = current;
		current = current -> next;
		free(before);
	}
	
	return 0;
}


