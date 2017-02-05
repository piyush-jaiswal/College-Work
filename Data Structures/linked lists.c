/* Develop a linked list system which implements the following functions:

p=makeNode(5) : makes a node with value 5 and next as null, returns the pointer to p

insert(p)   : inserts the node p in the linked list by attaching it in beginning

insert_sorted(p)   : inserts the node p in the list in sorted form

traverse();   : displays the entire list

p=search(5)   : searches for a node containing 5 and returns the address else returns NULL

initialze()   : deletes everything in the list if the start was non-null and makes start as NULL

p=remove_node(5);     searches for node containing 5 and removes it from the linked list, makes the next of the disconnected node as null and returns the disconnected node address into p.
.   */


#include<stdio.h>

struct node
{
  int data;
   struct node *next;
};
struct node *start=NULL;

struct node *makenode(int d)
{
   struct node *t;
   t=(struct node *)malloc(sizeof(struct node));
   t->data=d;
   t->next=NULL;
   return t;
}

insert(struct node *t)
{
   t->next=start;
   start=t;
}

insert_sorted(struct node *p)
{
    if(start==NULL)
    {
        p->next = start;
        start = p;
    }
    else
    {
        struct node *l,*q;
        l = start;
        while(l!=NULL)
        {
            if(l->data > p->data)
            break;
            q=l;
            l=l->next;
        }
        if(l==start)
                insert(p);
        else
        {
            p->next = q->next;
            q->next = p;
        }
    }
}

traverse()
{
    struct node *p;
    p=start;
    while(p!=NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

struct node *search(int x)
{
    struct node *p;
    p=start;
    while(p!=NULL)
    {
        if(p->data==x)
            return p;
            p=p->next;
    }
    return p;
}

initialize()
{
    start = NULL;
}

int *remove_node(int x)
{
    struct node *p,*q;
    int *r;
    p = start;
    while(p!=NULL)
    {
        if(p->data==x)
        break;
        q=p;
        p=p->next;
    }
    r=&p;
    if(p==start)
    {
        start = p->next;
        free(p);
    }
    else
    {
    q->next = p->next;
    free(p);
    }
    return r;
}

main()
{
    struct node *n;
    int *p;
    start=NULL;
    n=makenode(5);
    insert(n);
    n=makenode(7);
    insert_sorted(n);
    n=makenode(9);
    insert_sorted(n);
    traverse();
    n=search(7);
    if(n==NULL)
        printf("Not Found\n");
    else
        printf("Found %d\n", n->data);
    n=makenode(8);
    insert_sorted(n);
    traverse();
    p=remove_node(5);
    printf("Address of deleted node = %d\n", *p);
    traverse();
}

