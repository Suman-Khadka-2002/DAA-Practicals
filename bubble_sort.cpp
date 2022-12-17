// program to implement bubble sort algorithm

#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i=0 ; i<n-1 ; i++)
    {
        for (int j=0 ; j<n-i-1 ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

}
int main()
{
    int a[20], n;
    cout<<"Enter the total number of elements: ";
    cin>>n;
    cout<<"Enter the elements :\t";
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    // unsorted array
    cout<<"Unsorted array : ";
    for (int i=0; i<n; i++)
    {
        cout<<"-> "<<a[i];
    }
    bubbleSort(a, n);
// Display sorted array
    cout<<"\nSorted Array : ";
    for (int i=0; i<n; i++)
    {
        cout<<"-> "<<a[i];
    }
}