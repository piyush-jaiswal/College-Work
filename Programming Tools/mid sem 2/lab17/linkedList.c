#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Node.h"



bool isListEmpty(Node *Start)
{
	if(Start == NULL)
		return true;
	return false;
}


Node* newNode (int x)
{
	Node* new = malloc (sizeof(Node));
	new -> val = x;
	new -> next = NULL;
}


Node* insertAtBeg (Node *Start, Node* toBeInserted)
{
	if(!isListEmpty(Start))
		toBeInserted -> next = Start;
	Start = toBeInserted;
	return Start;
}


Node* deleteAtBeg (Node *Start)
{
	if(Start == NULL)
		return NULL;
	else
	{
		Node *toBeDeleted = Start;
		Start = Start -> next;
	
		free(toBeDeleted);
		return Start;
	}
}


Node* insertAtEnd (Node *Start, Node *toBeInserted)
{
 	Node *current = Start;	
 	
	if(isListEmpty (Start))
		Start = toBeInserted;
	else
	{
		while(current -> next != NULL)
			current = current -> next;
		current -> next = toBeInserted;
	}
	
	return Start;
}


Node* deleteAtEnd (Node *Start)
{
	Node *current = Start, *beforeCurrent;
	
	if(Start == NULL)
		return NULL;
	else
	{
		while(current -> next != NULL)
		{
			beforeCurrent = current;
			current = current -> next;
		}
		
		if(current == Start)
		{
			free(current);
			return NULL;
		}
		
		beforeCurrent -> next = NULL;
		free(current);
		return Start;
	}
}


void traverse (Node *Start)
{
	Node *current = Start;
	
	printf("Linked List:\n");
	while (current != NULL)
	{
		printf("%d\t", current -> val);
		current = current -> next;
	}
}
