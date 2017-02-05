#include<stdio.h>
#include<string.h>

struct rule
{
    char root[2];
    char production[20];
    char first[20];
};


//Finds the position of the root in the given array of productions
int root_position(struct rule grammar[], char root, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(grammar[i].root[0] == root)
            return i;
    }

    return -1;
}


//Computes first
void compute_first(struct rule grammar[], struct rule *x,  int n)
{

    //If the first is already computed
    if(strcmp(x->first, "") != 0)
        return;

    int len,i,root_pos;
    char ch, *ch_p;

    len = strlen(x->production);

    //If the production is epsilon
    if(x->production[0] == '0')
    {
        strcat(x->first,"0");
        return;
    }


    for(i=0; i<len; i++)
    {
        ch = x->production[i];

        //If it is a terminal
        if(ch>='a' && ch<='z')
        {
            ch_p = &ch;
            strcat(x->first, ch_p);
            return;
        }

        else
        {
            //If it is a non-terminal including epsilon
            root_pos = root_position(grammar, ch, n);
            compute_first(grammar, &grammar[root_pos], n);

            //If the production is epsilon
            if(grammar[root_pos].first[0] == '0')
            {

                //If the last production also has epsilon
                if(i == len-1) 
                    strcat(x->first,"0");
                continue;
            }
                
            strcat(x->first, grammar[root_pos].first);
            return;
        }
    }

}



int main()
{
    int n,i;

    printf("Enter the no. of productions\n");
    scanf("%d", &n);
    struct rule grammar[n];
    printf("Enter the grammar\n");

    for(i=0; i<n; i++)
    {
        printf("Root: ");
        scanf("%s", grammar[i].root);

        printf("Production: ");
        scanf("%s", grammar[i].production);
        strcpy(grammar[i].first,""); //Initializing first of every structure
    }


    //Computing first for every production
    for(i=0; i<n; i++)
    {
        compute_first(grammar, &grammar[i], n);
    }

    for(i=0; i<n; i++)
    {
        printf("\n\n");
        printf("Root: ");
        puts(grammar[i].root);
        printf("First: ");
        puts(grammar[i].first);
    }
}