/*   3.	Wap to add, multiply and subtract two matrices using the concept of
b.	Operator member function     */                   

#include<iostream>
#include<conio.h>
 
using namespace std;

class matrix
{
 	  int m[100][100];
 	  int row, column;
 	  public:
	  		 matrix() { }
	  		 matrix(int a, int b)
	  		 {
	  		     int i,j;
	  		     row = a;
	  		     column = b;
	  		     cout<<"Enter the elements"<<endl;
	  		     for(i=0; i<row; i++)
	  		     {
  	                   for(j=0; j<column; j++)
				  	   {
					   		cin>>m[i][j];
						}
                 }
			 }
			
			 matrix operator+ (matrix);
			 matrix operator- (matrix);
		     matrix operator* (matrix);
		     void display();
};

matrix matrix:: operator+ (matrix a)
{
 	   if(a.row!=row || a.column!=column)
	   {
		 	cout<<"Cannot be added"<<endl<<endl;
		 	a.row = 0;
		 	a.column = 0;
            return a;
       }
       matrix temp;
       temp.row = a.row;
       temp.column = a.column;
	   int i,j;
	   for(i=0; i<a.row; i++)
 			{
 		    for(j=0; j<a.column; j++)
		       {
	  		    temp.m[i][j] = a.m[i][j] + m[i][j];  // addition of matrices
               }
       }
       return temp;
}

matrix matrix :: operator- (matrix b)
{
 	   if(row!=b.row || column!=b.column)
	   {
		 	cout<<"Cannot be subtracted"<<endl<<endl;
		 	row = 0;
		 	column = 0;
            return *this;
       }
       matrix temp;
       temp.row = row;
       temp.column = column;
	   int i,j;
	   for(i=0; i<row; i++)
 			{
 		    for(j=0; j<column; j++)
		       {
	  		    temp.m[i][j] = m[i][j] - b.m[i][j]; //subtraction of matrices
               }
       }
       return temp;
}			                 
					 			
matrix matrix :: operator* (matrix b)
{
 	   if(column != b.row)
		{
		    cout<<"Multiplication not possible"<<endl<<endl;
			row = 0;
			column = 0;
			return *this;
		}
		matrix temp;
		temp.row = row;
		temp.column = b.column;
		int i,j,k;					   			
		for(i=0; i<row; i++)
 			{
 		    for(j=0; j<column; j++)
		       {
			   		 for(k=0; k<b.row; k++)
			   		 {
					  		  temp.m[i][j]+= m[j][k] * b.m[k][j]; //multiplication of matrices
		             }
			   }
	         }
         return temp;
}

void matrix :: display()
{
 	 if(row==0 && column==0)
        return;
 	 cout<<endl;
 	 int i,j;
 	 for(i=0; i<row; i++)
 			{
 		    for(j=0; j<column; j++)
		       {
	  		    cout<<m[i][j]<<"\t";
               }
               cout<<endl;
             }
      cout<<endl;
}

int main()
{
 	int x,y;
 	cout<<"Enter the no. of rows and columns"<<endl; // inputting first matrix
    cin>>x;
    cin>>y;
    matrix a(x,y);
 	
 	cout<<"Enter the no. of rows and columns"<<endl; // inputting second matrix
    cin>>x;
    cin>>y;
    matrix b(x,y);
    
    cout<<endl;
 	matrix c;
 	cout<<"Addition"<<endl; //Addition using friend
 	c = a+b;
    c.display(); 
 	
 	cout<<"Subtraction"<<endl;  //Subtraction using friend
 	c = a-b; 	
 	c.display();
 	
 	cout<<"Multiplication"<<endl;  //Multiplication using friend
    c = a*b;
 	c.display();
 	
 	getch();
 	return 0;
}
