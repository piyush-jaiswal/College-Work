/* Do all these questions by applying concept of static data member, static member function, const member function, 
inline function( Explicit , Implicit), nesting member function and Default Arguments:
       6.	Write a C++ program to write a function, char* findx(const char* s, const char* x), that finds the first occurrence of the string x in s. */
       
#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

char* findx(const char*s, const char*x)
{
      char *p;
      int lns, lnx, i, ct, f=0;
      lns = strlen(s);
      lnx = strlen(x);
      for(i=0; i<lns-lnx; i++)
      {
               if(s[i]==x[0])
               {
 				     f=0;
 				     ct=1;
			   	     while(ct<lnx && f==0)
			   	     {
  				         if(s[i+ct]!= x[ct])
	         			      f=1;
		      		     ct++;
						 }
						 if(f==0)
						 {
			 		         p = (char*)&s[i];
			 		         return p;
			 		         
						 }
						 }
					 	}
						 }
						 
int main()
{
 	char s[100], x[100];
 	int i;
 	cout<<"Enter the main string"<<endl;
 	cin>>s;
 	cout<<"Enter the string to be found"<<endl;
 	cin>>x;
 	char *p; 
	 p = findx(s,x);
 	for(i=0; i<strlen(x)-1; i++)
 	{
	 		 cout<<p;
	 		 
	 }
			 getch();
			 return 0;
}
			 
			 
                
