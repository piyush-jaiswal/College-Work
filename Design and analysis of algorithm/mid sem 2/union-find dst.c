#include<stdio.h>
#include<malloc.h>

struct node
{
	int value;
	struct node *link;
	int rank;
};

struct node* arr[100];

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


int lsearch(int n, int p)
{
    int i;
    for(i=0; i<p; i++)
    {
        if(arr[i]->value == n)
            return i;
    }

    return -1;
}

int main()
{
    int ch=1,n,p=0,m,ai,bi;
    struct node *a, *b, *c;
    a =(struct node *) malloc(sizeof(struct node));
    b =(struct node *) malloc(sizeof(struct node));
    c =(struct node *) malloc(sizeof(struct node));

    /*a = makeSet(4);
    b = makeSet(6);

    c = findSet(a);
    printf("Set = %d\n", c->value);
    c = findSet(b);
    printf("Set = %d\n", b->value);

    unionSet(a,b);
    c = findSet(a);
    printf("Set = %d\n", c->value);
    c = findSet(b);
    printf("Set = %d\n", b->value);*/



    while(ch!=4)
    {
        printf("\nPress 1 to make set\n");
        printf("Press 2 to find set\n");
        printf("Press 3 to union set\n");
        printf("Press 4 to exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);

        switch(ch)
        {
        case 1:
            printf("Enter the value\n");
            scanf("%d", &n);
            a = makeSet(n);
            arr[p++] = a;
            break;

        case 2:
            printf("Enter the value\n");
            scanf("%d", &n);
            ai = lsearch(n,p);
            if(ai==-1)
            {
                printf("No such value\n");
                break;
            }

            b = findSet(arr[ai]);
            printf("Set = %d\n", b->value);
            break;

        case 3:
            printf("Enter the values\n");
            scanf("%d %d", &m,&n);
            ai = lsearch(m,p);
            bi = lsearch(n,p);

            if(ai==-1 || bi==-1)
            {
                printf("No such value\n");
                break;
            }

            unionSet(arr[ai],arr[bi]);
            break;

        case 4:
            break;

        default:
            printf("Wrong value entered\n");
        }
    }

    return 0;
}
