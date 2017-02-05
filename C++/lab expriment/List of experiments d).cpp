  /*4.	Write a C++ program that prompts the user to enter three integer values, and then outputs the values in numerical distuence separated by commas. So, if the 
user enters the values 10,4,6, the output should be 4,6,10. If two values are the same, they should just be ordered together. So, the input
 4,5,4 should give 4,4,5.  */
 
#include<iostream>
#include<conio.h>
using namespace std;
class dist
{
    int ar[3];
public:
    void getdata();
    void distance();
    void display();
};

void dist::getdata()
{int i;
    for(i=0;i<3;i++)
    {
        cout<<"Enter the "<<i+1<<" distance:";
        cin>>ar[i];
    }
}

void dist::distance()
{
    int temp,i,j,l=3;
    for(i=0;i<l-1;i++)
    {
        for(j=0;j<l-i-1;j++)
        {
            if(ar[j]>ar[j+1])
                {
                    temp=ar[j];
                    ar[j]=ar[j+1];
                    ar[j+1]=temp;
                }
        }
    }
}
 
void dist::display()
{
    int i;
    cout<<"distance wise:";
    for(i=0;i<3;i++)
    {
        if(i==2)
            cout<<ar[i]<<".";
        else
            cout<<ar[i]<<",";
    }
}

int main()
{
    dist s1;
    s1.getdata();
    s1.distance();
    s1.display();
}

