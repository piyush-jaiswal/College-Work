/* Q)  1) Implement the binary trees algorithms by writing makenode() insert() traverse()

2) Now add a function search(5) which will search for 5 in the tree and report if it is found or not.

3) Make a function called count() which can find the total number of nodes in the tree.

4) Add a function called delete(5) which will remove the node containing 5 from the tree. Take care of all situations and test your logic by deleting
   various nodes and drawing the tree visualization to understand if all cases are working or not.

5) Make a function which can find out the height of a tree.
   x=height(root); */

#include<stdio.h>

struct node
{
    int data;
    struct node *left, *right;
};
struct node *root = NULL;
int c=0;


struct node *makenode(int d)
{
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = d;
    p->left = NULL;
    p->right = NULL;
    return p;
}

insert(struct node *p)
{
    struct node *t,*q;
    if(root==NULL)
    {
        root=p;
        return;
    }
    t = root;
    while(t!=NULL)
    {
        q=t;
        if(p->data < t->data)
            t = t->left;
        else
            t = t->right;
    }
    if(p->data < q->data)
        q->left = p;
    else
        q->right = p;
}

struct node *insert_rec(struct node *p, struct node *root)
{
    if(root==NULL)
        return p;
        if(p->data < root->data)
            root->left = insert_rec(p, root->left);
        else
            root->right = insert_rec(p, root->right);
        return root;
}

traverse(struct node *r)
{
    if(r)
    {
        traverse(r->left);
        printf("%d\n", r->data);
        traverse(r->right);
    }
}

struct node *search(int d)
{
    struct node *p;
    p = root;
    int ct=0;
    while(p!=NULL)
    {
        ct++;
        if(p->data==d)
            break;
        else
        {
            if(d<p->data)
                p=p->left;
            else
                p=p->right;
        }
    }
    printf("No. of comparisions = %d\n", ct);
    return p;
}

count(struct node *r)
{
    if(r)
    {
        count(r->left);
        c++;
        count(r->right);
    }
}

Delete(int d)
{
    struct node *n = root, *p, *t;
    int isleft=0;
     while(n!=NULL)
    {
        if(n->data==d)
            break;
        else
        {
            if(d<n->data)
            {
                p=n;
                n=n->left;
                isleft=1;
            }
            else
            {
                p=n;
                n=n->right;
                isleft=0;
            }
        }
    }
    printf("p = %d\n", p->data);

    t = n->right;
    if(t)
    {
    while(t->left!=NULL)
        t = t->left;
    t->left = n->left;
    }
    if(isleft)
        p->left = n->right;
    else
        p->right = n->right;

}

int height(struct node *p)
{
    int max,hl,hr;
    if(p==NULL)
        return 0;
    hl = height(p->left);
    hr = height(p->right);
    if(hl>hr)
        max = hl;
    else
        max = hr;
    return (max+1);
}



main()
{
    struct node *n,*p;
    n = makenode(5);
    root = insert_rec(n, root);
    n = makenode(3);
    insert_rec(n, root);
    n = makenode(2);
    insert_rec(n, root);
    n = makenode(4);
    insert_rec(n, root);
    n = makenode(7);
    p = insert_rec(n, root);
    n = makenode(6);
    insert_rec(n, root);
    n = makenode(10);
    insert_rec(n, root);
    traverse(root);
    n = search(7);
    printf("\n\n");
    printf("Searching for 7\n");
    if(n)
        printf("Found \n");
    else
        printf("Not Found\n");
    count(root);
    printf("Total nodes = %d\n", c);
    printf("\n\n");
    printf("\n\n height = %d", height(root));
}
