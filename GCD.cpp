// CPP program to find the GCD(Greatest Common Divisor) between two user input numbers

#include <iostream>
using namespace std;

int findgcd(int a, int b)
{
    if (a == 0)
        cout<<b<< " is the GCD";
    else if (b == 0)
        cout<<a<< " is the GCD." ; 
    else{
        while(b!=0)
        {
            int rem = a%b;
            a = b;
            b = rem;
        }
        cout<< a <<" is the GCD";
    }
}

int main()
{
    int a, b;
    cout<<"enter value of a: ";
    cin>>a;
    cout<<"enter value of b: ";
    cin>>b;
    findgcd(a, b);
}