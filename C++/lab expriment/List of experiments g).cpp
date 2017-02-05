/* g) Write a C++ program to print the accepted number and its reverse number.  */

#include<iostream>

using namespace std;

int main()
{
    int n,rev=0,d;

    cout<<"Enter the no :\t";
    cin>>n;

    while(n>0)
    {
        d=n%10;
        rev=rev*10+d;
        n/=10;
    }
    cout<<"Reverse of the number : "<<rev<<endl;

    return 0;
}

