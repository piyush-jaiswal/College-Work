/*Do all these questions by applying concept of static data member, static member function, 
const member function, inline function( Explicit , Implicit), nesting member function and 
Default Arguments:
4.	Write a function that using randint() from the previous exercise. Computes a pseudorandominteger
 in the range(a:b). rand_in_range(int a, int b). */
 
 #include<iostream>
 #include<stdlib.h>
 #include<conio.h>
 #include<ctime>
 
 using namespace std;
 
 class random
 {
       public:
              static int rand_in_range(int,int);
};

int random :: rand_in_range(int a =0, int b=50)
{
    int x = -5;
    time_t t;
    srand((unsigned) time(&t));
    while(x<a)
        x = rand()%b;
        return x;
}

int main()
{
    int a,b;
    cout<<"Enter the lower and upper limit"<<endl;
    cin>>a>>b;
    cout<<"Random no. = "<<random:: rand_in_range(a,b);
    getch();
    return 0;
}
