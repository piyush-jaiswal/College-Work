/* Q) Merge two sorted linked lists in sorted order. */



#include<stdio.h>
#include"linkedlists.c"

struct node *merge(struct node *start1,struct node *start2)
{
    struct node *p,*q,*r,*start;
    p=start1;
    q=start2;
    r=NULL;
    start=NULL;
    if(p->data < q->data)
    {
        r=p;
        start=r;
        p=p->next;
    }
    else
    {
        r=q;
        start=r;
        q=q->next;
    }
    printf("start = %d\n", start->data);
    while(p!=NULL && q!=NULL)
    {
       if(p->data < q->data)
        {
            r->next=p;
            p=p->next;
            r=r->next;
        }
        else
        {
            r->next=q;
            q=q->next;
            r=r->next;
        }
    }

    if(p==NULL)
    {
        while(q!=NULL)
        {
            r->next=q;
            r=r->next;
            q=q->next;
        }
    }
    else
    {
        while(p!=NULL)
        {
            r->next=p;
            r=r->next;
            p=p->next;
        }
    }
    return start;
}

main()
{

    struct node *start1,*start2,*n,*startm;
    initialize();
    n=makenode(5);
    insert_sorted(n);
    start1=n;
    n=makenode(9);
    insert_sorted(n);
    n=makenode(12);
    insert_sorted(n);
    traverse();
    printf("start1 = %d\n\n",start1->data);
    initialize();
    n=makenode(1);
    insert_sorted(n);
    start2=n;
    n=makenode(6);
    insert_sorted(n);
    n=makenode(10);
    insert_sorted(n);
    n=makenode(15);
    insert_sorted(n);
    n=makenode(20);
    insert_sorted(n);
    traverse();
    printf("start2 = %d\n\n",start2->data);
    startm = merge(start1,start2);
    traverse2(startm);
}
