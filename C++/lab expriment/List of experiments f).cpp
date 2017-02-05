 /*5.	Write a C++ program to read a sequence of double values into a vector. Think of each value as the distance between two cities along a given route. 
 Compute and print the total distance. Find and print the smallest and greatest distance between two neighbouring cities. Find and print the mean distance 
 of the neighbouring cities.  */

#include<iostream>
#include<math.h>
using namespace std;
class vector
{
int x[3],y[3];
float dist[3];
public:
void getdata();
void caldist();
void largest();
void smallest();
};

void vector :: getdata()
{  int i;
   cout<<"Enter the values"<<endl;
  for(i=0;i<3;i++)
  { cout<<"Values no."<<i<<":";
    cin>>x[i]>>y[i];
  }
}
void vector:: caldist()
{ int i;
  cout<<"The respective distances are "<<endl;
   for(i=0;i<3;i++)
   { cout<<"distance no."<<i<<":" ;
     dist[i]= sqrt((x[i]*x[i])+ (y[i]*y[i]));
     cout<<dist[i]<<endl;
   }
  }
void vector::largest()
{ int max,i;
  max=dist[0];
  for(i=1;i<3;i++)
  { if(dist[i]>max)
     {max=dist[i];}
  }
  cout<<"Max distance is:"<<max<<endl;
}
void vector::smallest()
{ int min,i;
  min=dist[0];
  for(i=1;i<3;i++)
  { if(dist[i]<min)
     {min=dist[i];}
  }

cout<<"Min distance is:"<<min<<endl;
}

int main()
{ vector ob;
  ob.getdata();
  ob.caldist();
  ob.largest();
  ob.smallest();
  return 0;
}

