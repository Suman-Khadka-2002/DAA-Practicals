// program to implement selection sort

#include<iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int least = arr[i];
        int p = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < least)
            {
                least = arr[j];
                p = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[p];
        arr[p] = temp;
    }
}

int main()
{
    cout<<"Enter the total number of elements: ";
    int n;
    cin>>n;
    int a[n];
    cout<<"\nEnter the elements: \n";
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"\nUnsorted Array:  ";
    for (int i=0; i<n; i++)
    {
        cout<<a[i]<<"\t";
    }
    selectionSort(a, n);
    cout<<"\nSorted Array:  ";
    for (int i=0; i<n; i++)
    {
        cout<<a[i]<<"\t";
    }
}