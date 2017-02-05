#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<ctime>

using namespace std;

int randint(int n)
{
    time_t t;
    srand((unsigned) time(&t));
    return (rand()%n);
}

int main()
{
    int maxint;
    cout<<"Enter the maximum limit"<<endl;
    cin>>maxint;
    cout<<"Random no. = "<<randint(maxint);
    getch();
    return 0;
}
    
