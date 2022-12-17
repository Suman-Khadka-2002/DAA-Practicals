// program implementing insertion sort

#include<iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        int temp = arr[i];
        int j = i-1;
        while (j >=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = temp;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int a[n];
    cout<<"\nEnter the elements : \n";
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"\nUnsorted array : \n";
    for (int i=0; i<n; i++)
    {
        cout<<"-> "<<a[i];
    }
    insertionSort(a, n);
    cout<<"\nSorted Array is : \n";
    for (int i=0; i<n; i++)
    {
        cout<<"-> "<<a[i];
    }
}