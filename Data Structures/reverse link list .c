#include<stdio.h>
#include"linkedlists.c"

struct node *reverse()
{
    struct node *p,*q,*r,*startr;
    p=start;
    q=p->next;
    p->next = NULL;
    r=q->next;
    q->next=p;
    p=r;
    while(p!=NULL)
    {
        r=p->next;
        p->next=q;
        q=p;
        p=r;
    }
    startr=q;
    return startr;
}

main()
{
    struct node *n, *startr;
    n=makenode(1);
    insert(n);
    start=n;
     n=makenode(2);
    insert(n);
     n=makenode(3);
    insert(n);
     n=makenode(4);
    insert(n);
     n=makenode(5);
    insert(n);
     n=makenode(6);
    insert(n);
    traverse();
    printf("\n\n");
    startr = reverse();
    traverse2(startr);
}
