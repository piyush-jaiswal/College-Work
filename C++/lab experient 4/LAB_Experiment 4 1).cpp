/*1.	Wap to overload the following operator for the complex number using friend function:
a.	*(multiplication operator)        c. ( / ) division operator  */

#include<iostream>
#include<conio.h>

using namespace std;

class complex
{
 	  float real;
 	  float imag;
 	  public:
 	  complex(){ }
 	  complex(float a, float b)
 	  {
           real = a;
           imag = b;
      }
      friend complex operator*(complex, complex);
      friend complex operator/(complex, complex);
      void displaymult();
      void displaydiv();
};

complex operator*(complex a, complex b)
{
 		complex temp;
 		temp.real = a.real*b.real - a.imag*b.imag;
 		temp.imag = a.real*b.imag + a.imag*b.real;
 		return temp;
}

complex operator/(complex a, complex b)
{
      complex temp, m;
      float den;
      b.imag = -b.imag;
      m = a*b;
      den = (b.real*b.real + b.imag*b.imag);
      temp.real = m.real/den;
      temp.imag = m.imag/den;
      return temp;
}    

void complex:: displaymult()
{
 	 cout<<"Multiplication = "<<real<<" + i("<<imag<<")"<<endl;
}

void complex :: displaydiv()
{
 	 cout<<"Division = "<<real<<" + i("<<imag<<")"<<endl;
}
	 
int main()
{
 	complex x,y,w;
 	float a,b;
 	cout<<"Enter the first complex no"<<endl;
 	cin>>a;
 	cin>>b;
 	x = complex(a,b);
 	cout<<"Enter the second complex no"<<endl;
 	cin>>a;
 	cin>>b;
 	y = complex(a,b);
 	complex z = x*y;
 	z.displaymult();
 	w = x/y;
 	w.displaydiv();
 	getch();
 	return 0;
}
 	


	 
		
      
		   
