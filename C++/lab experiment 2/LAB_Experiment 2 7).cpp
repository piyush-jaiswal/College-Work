/*Do all these questions by applying concept of static data member, static member function, const member function, inline function( Explicit , Implicit), 
nesting member function and Default Arguments:
7.	Define a singly-linked list, slist, and perform operations insertion, deletion and traverse.  */




#include<iostream>
#include<conio.h>

using namespace std;

class node
{
	int data;
	node *next;
	public:
		friend node* new_node(int);
		friend void insert(node*);
		friend void del(int);
		friend void traverse();
}*start=NULL;

node* new_node(int x)
{
	node *t = new node();
	t->data = x;
	t->next = NULL;
	return t;
}

void insert(node *ptr)
{
	if(start==NULL)
		start = ptr;
	else
	{
		ptr->next = start;
		start = ptr;
	}
}

void del(int x)
{
	node *p,*q;
	p = start;
	while(p->data!=x && p!=NULL)
	{
		q=p;
		p = p->next;
	}
	if(p==start)
	{
		start = start->next;
		delete(p); 
	}
	else if(p==NULL)
		return;
	else
	{
		q->next = p->next;
		delete(p);
	}
}

void traverse()
{
	node *p;
	p = start;
	while(p!=NULL)
	{
		cout<<p->data<<endl;
		p = p->next;
	}
}
	
int main()
{
	node *p;
	p = new_node(14);
	insert(p);
	p = new_node(15);
	insert(p);
	p = new_node(16);
	insert(p);
	p = new_node(17);
	insert(p);	
	p = new_node(18);
	insert(p);
	p = new_node(19);
	insert(p);
	p = new_node(20);
	insert(p);
	traverse();
	del(16);
	cout<<endl;
	traverse();
	getch();
	return 0;
}
