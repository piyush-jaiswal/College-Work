 /*  3. Wap to demonstrate the use of function overloading by considering all the permutation-combinations over the policies applied by Compiler for 
 selecting appropriate function among set of available function definitions. */
 
#include<iostream>
#include<conio.h>
using namespace std;
float volume( char l, int b, int h)
{
      return l*b*h;
}
int volume( int r, int h)
{
    return( 3.14*r*r*h);
}
int volume(int side)
{
    return side*side*side;
}
int main()
{
 cout<<"The volume of the cuboid is: "<<volume(20,20,30)<<endl;
 cout<<"The volume of the cylinder is: "<<volume(20,30)<<endl; 
 cout<<"The volume of the cube is: "<<volume(30)<<endl;
 getch();
 return 0;
}

