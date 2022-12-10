// CPP program to find the fibonacci number of nth element

#include<iostream>
using namespace std;

int fibo(int a, int b, int n)
{
    int i=3, temp;
    while(i<=n){
        temp = a+b;
        a = b;
        b = temp;
        i++;
    }
    return temp;
}

int main()
{
    int first = 0, second = 1;
    int n;
    cout<<"enter the term which you want to calculate: ";
    cin>>n;
    cout<<"the fibonacci number of element "<<n<<" is "<<fibo(first, second, n);
}