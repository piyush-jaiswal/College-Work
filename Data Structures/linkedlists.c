
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

insert( struct node *t)
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
        start = p;
        free(p);
    }
    else
    {
    q->next = p->next;
    free(p);
    }
    return r;
}

traverse2(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d\n", p->data);
        p=p->next;
    }
}


