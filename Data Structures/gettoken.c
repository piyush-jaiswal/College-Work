#include<stdio.h>

char *gettoken(char *p, int i)
{
    static char dummy[100];
    int pos_of_dummy=0;
    if((p[i]=='+') || (p[i]== '-') || (p[i]=='*') || (p[i]=='/') || (p[i]=='(') || (p[i]==')'))
    {
        dummy[pos_of_dummy++] = p[i];
        dummy[pos_of_dummy] = '\0';
        return dummy;
    }
    else
    {
        while(isdigit(p[i]) || p[i]==' ')
        {
            dummy[pos_of_dummy++] = p[i];
            i++;
        }
        dummy[pos_of_dummy]='\0';
        return dummy;
    }
}

