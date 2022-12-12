// program to implement selection sort

#include<iostream>
using namespace std;

void selctionSort(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        int least = arr[i];
        int p = i;
        for (int j=i+1; j<n; j++)
        {
            if (arr[j]<arr[i])
            {
                least = arr[j];
                p = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[p];
        arr[p] = temp;
    }
    cout<<"\nSorted Array:  ";
    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<"\t";
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

    selctionSort(a, n);
}