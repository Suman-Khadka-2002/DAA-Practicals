// CPP program to find the fibonacci number of nth element

#include<iostream>
using namespace std;

int fibo(int n)
{
    if (n<=1)   
        return n;
    else
        return (fibo(n-1) + fibo(n-2));
}

int main()
{
    int n;
    cout<<"enter the term which you want to calculate: ";
    cin>>n;
    cout<<"the fibonacci number of element "<<n<<" is "<<fibo(n);
}