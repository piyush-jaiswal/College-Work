/*  Do all these questions by applying concept of static data member, static member function, const member function,
 inline function( Explicit , Implicit), nesting member function and Default Arguments:

 5.	Write a C++ program to write a function void to_lower(char* s) that replaces all uppercase characters.
 Don‟t use any standard library functions.  */


#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

class lower
{
    static char s[100];
public:
    void to_lower();
};
char lower::s[100] = "rajat";

void lower:: to_lower()
{
    int ln,i,ascii;
    ln= strlen(s);
    for(i=0;i<ln;i++)
    {
        ascii = (int)s[i];
        if(ascii>=97 && ascii<=122)
            s[i] = (char)ascii - 32;
    }
    cout<<s<<endl;
}

int main()
{
    lower ob;
    ob.to_lower();
    getch();
    return 0;
}
