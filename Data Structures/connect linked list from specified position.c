/* Q) Connect the linked list from the specified position. */



#include<stdio.h>
#include"linkedlists.c"

struct node *connect(int m1, struct node *start1, struct node *start2)
{
    struct node *p1,*start,*p2,*q,*dummy;
    int c=0;
    p1=start1;
    p2=start2;
    q=p1;
    if(m1>0)
    {
        start=start1;
        while(c<m1)
        {
            q=p1;
            p1=p1->next;
            c++;
        }
        dummy=q->next;
        q->next = start2;
    }
    else
    {
        start=start2;
        dummy=start1;
    }
    while(p2->next!=NULL)
        p2=p2->next;
    p2->next = dummy;
    return start;
}

main()
{

    struct node *start1,*start2,*n,*start;
    initialize();
    n=makenode(1);
    insert_sorted(n);
    start1=n;
    n=makenode(5);
    insert_sorted(n);
    n=makenode(12);
    insert_sorted(n);
     n=makenode(7);
    insert_sorted(n);
     n=makenode(9);
    insert_sorted(n);
    traverse();
    printf("start1 = %d\n\n",start1->data);
    initialize();
    n=makenode(2);
    insert_sorted(n);
    start2=n;
    n=makenode(3);
    insert_sorted(n);
    n=makenode(4);
    insert_sorted(n);
    traverse();
    printf("start2 = %d\n\n",start2->data);
    start = connect(5,start1,start2);
    printf("Connect from %d\n", 5);
    traverse2(start);
}

