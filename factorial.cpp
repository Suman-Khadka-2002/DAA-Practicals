// CPP program to find the factorial of a user input number

#include<iostream>
using namespace std;

int factorial(int num)
{
    if (num>1)
        return num * factorial(num-1);
    else if (num == 0)
    {
        cout<<"The factorial is 1.";
        exit(0);
    }
    else if(num<1){
        cout<<"Invalid number";
        exit(1);
    }

}

int main()
{
    int num;
    cout<<"enter a number to find the factorial of: ";
    cin>>num;

    cout<<"The factorial of the number "<<num<< " is : "<<factorial(num);
}