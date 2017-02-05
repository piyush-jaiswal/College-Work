#include<stdio.h>
#include<malloc.h>

struct node
{
	int value;
	struct node *link;
	int rank;
};


struct node *makeSet(int x)
{
	struct node *p;
	p =(struct node *)malloc(sizeof(struct node));
	p->value = x;
	p->link = p;
	p->rank = 0;
	return p;
}

struct node *findSet(struct node *x)
{
	if(x->link!= x)
		x->link = findSet(x->link);
	return x->link;
}

void unionSet(struct node *x, struct node *y)
{
	struct node *a, *b;
	a =(struct node *) malloc(sizeof(struct node));
	b =(struct node *) malloc(sizeof(struct node));

	a = findSet(x);
	b = findSet(y);

	if(a->rank > b->rank)
    {
        //printf("A rank = %d\n", a->rank);
        //printf("B rank = %d\n", b->rank);
		b->link = a;
    }
	else if(b->rank > a->rank)
		a->link  = b;

	else
	{
	    //printf("Inside else\n");
		a->link = b;
		b->rank = b->rank+1;
	}
}
