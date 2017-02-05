#include<stdio.h>
#include"linkedlists.c"

deletebelow(int d)
{
    struct node *p,*q,*r;
    p=start;
    q=p;
    while(p!=NULL)
    {
        if(p->data<=d)
        {
            if(p==start)
                start = p->next;
        q->next = p->next;
        r=p;
        p=p->next;
        free(r);
        }
        else
        {
            q=p;
            p=p->next;
        }
    }
}


main()
{
    struct node *n;
    n=makenode(5);
    insert(n);
    start=n;
     n=makenode(6);
    insert(n);
     n=makenode(9);
    insert(n);
     n=makenode(10);
    insert(n);
    traverse();
    printf("\n\n");
    printf("Deleting below 9\n\n");
    deletebelow(9);
    traverse();
}
