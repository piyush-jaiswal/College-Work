// 7) Copy from word
 
#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{
    int i;
    int sum=0;
    float n;
    cout<<"enter the value of n : ";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        sum=sum+i;
    }
    float variance=(1/n)*((sum*sum)+(sum/n)*(sum/n)-2*(sum/n)*(sum));
    float standard_variance=sqrt((variance));
    cout<<" variance : "<<variance<<endl;
    cout<<" standard_variance :"<<standard_variance<<endl;
    getch();
    return 0;
}

