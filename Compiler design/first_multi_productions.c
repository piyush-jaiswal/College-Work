#include<stdio.h>
#include<string.h>

struct rule
{
    int firstComputed;
    int no_of_production;
    char root[2];
    char production[5][20];
    char first[20];
};

void compute_for_root( struct rule *x, int n, struct rule grammar[]);
void compute_first(struct rule grammar[], struct rule *x, int n, int production_pos);


///Finds the position of the root in the given array of productions
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



//Computes first of the root for all its productions
void compute_for_root( struct rule *x, int n, struct rule grammar[])
{
    int r=0,j;
    for(j=0; j< x->no_of_production; j++)
    {
        compute_first(grammar, x, n, r);
        r++;
    }
    x->firstComputed = 1;
}





//Computes first of a production
void compute_first(struct rule grammar[], struct rule *x, int n, int production_pos)
{

    //If the first is already computed
    if(x->firstComputed == 1)
        return;

    //If the production is epsilon
    if(x->production[production_pos][0] == '0')
    {
        strcat(x->first,"0");
        return;
    }


    

    int len,i,root_pos,f=0,j, len_of_first;
    char ch, *ch_p, ch2, *ch2_p;

    len = strlen(x->production[production_pos]);

    for(i=0; i<len; i++)
    {
        ch = x->production[production_pos][i];

        //If it is a terminal
        if(ch>='a' && ch<='z')
        {
            ch_p = &ch;
            strcat(x->first, ch_p);
            return;
        }

        else
        {
            //If it is a non-terminal, find its position and compute its first
            root_pos = root_position(grammar, ch, n);
            compute_for_root(&grammar[root_pos], n, grammar);

            f = 0;
            len_of_first = strlen(grammar[root_pos].first);
            //Add all except epsilon
            for(j=0; j<len_of_first; j++)
            {
                ch2 = grammar[root_pos].first[j];
                
                //If the first contains epsilon
                if(ch2 == '0')
                {
                    f = 1;
                    continue;
                }

                ch2_p = &ch2;
                strcat(x->first, ch2_p); 
            }

            //If the first has epsilon
            if(f == 1)
            {
                //If it is the last non-terminal
                if(i == len-1)
                    strcat(x->first,"0");
                    
                continue;
            }

            return;
        }
    }

}



int main()
{
    int n,i,j,r;

    printf("Enter the no. of roots in the grammar\n");
    scanf("%d", &n);
    struct rule grammar[n];
    printf("Enter the grammar\n");

    for(i=0; i<n; i++)
    {
        j=0;
        printf("Root: ");
        scanf("%s", grammar[i].root);

        printf("Enter the no. of productions of the root\n");
        scanf("%d", &r);
        grammar[i].no_of_production = r;

        while(r>0)
        {
            printf("Production: ");
            scanf("%s", grammar[i].production[j++]);
            r--;
        }
        strcpy(grammar[i].first,""); //Initializing first of every structure
        grammar[i].firstComputed = 0;
    }


   /* for(i=0; i<n; i++)
    {
        r=0;
        for(j=0; j<grammar[i].no_of_production; j++)
        {
            puts(grammar[i].production[r++]);
        }
    }*/

    //Computing first for every production
    for(i=0; i<n; i++)
    {
        compute_for_root(&grammar[i], n, grammar);
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
