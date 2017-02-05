/* Q) Reverse the liked list. */



#include<stdio.h>
#include"linkedlists.c"

struct node *reverse(struct node *start)
{
    struct node *p,*startr;
    int c=0, pos=0;
    p=start;
    while(p->next!=NULL) //counting the no, of elements
    {
        p=p->next;
        c++;
    }
    struct node *ar[c]; //array of node pointers to store the links
    p=start;
    while(p->next!=NULL)// storing the links
    {
        ar[pos++] = p->next;
        p=p->next;
    }
    pos--;
    p->next = ar[pos--];
    startr = p;// starting position of the reversed list
    p=p->next;
    while(pos>=0)// assigning the links from the array in order to reverse it.
    {
        p->next = ar[pos--];
        p=p->next;
    }
    p->next=start; // These 2 lines are specifically for the last and the second last elements whose links are not stored in the array
    start->next=NULL;
    return startr;
}

main()
{
    struct node *startr,*n;
    n=makenode(1);
    insert_sorted(n);
    start=n;
    n=makenode(2);
    insert_sorted(n);
    n=makenode(3);
    insert_sorted(n);
    n=makenode(4);
    insert_sorted(n);
    traverse();
    printf("\n\n");
    startr = reverse(start);
    traverse2(startr);
}
