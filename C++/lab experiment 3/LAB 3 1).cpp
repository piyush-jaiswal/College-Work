/* LAB-3
1.	Wap to demonstrate call by reference for GCD an LCM.  */



#include<iostream>
#include<conio.h>

using namespace std;

class refer
{
public :
    int gcd(int &a, int &b)
    {
        int low, hcf,i;
        if(a>b)
            low=b;
        else
            low=a;
        for(i=low;i>=1;i--)
        {
            if(a%i==0 && b%i==0)
            {
                hcf = i;
                break;
            }
        }
        return hcf;
    }

    int lcm(int &a, int &b)
    {
        int high, lcm, i;
        if(a>b)
            high=a;
        else
            high=b;
        for(i=high; i<=a*b; i++)
        {
            if(i%a==0 && i%b==0)
            {
                lcm = i;
                break;
            }
        }
        return lcm;
    }
};

int main()
{
    refer ob = refer() ;
    int a,b,cp1,cp2;
    cout<<"Enter the nos"<<endl;
    cin>>a>>b;
    cp1=a;
    cp2=b;
    cout<<"GCD = "<<ob.gcd(a,b)<<endl;
    cout<<"a ="<<cp1<<" b ="<<cp2<<endl;
    cp1 = a;
    cp2 = b;
    cout<<"LCM = "<<ob.lcm(a,b)<<endl;
    cout<<"a = "<<cp1<<" b = "<<cp2<<endl;
    getch();
    return 0;
}
