// CPP program to implement Binary search algorithm using OOP.

#include<iostream>
using namespace std;

class BinarySearch {
public:
    int *arr;

    int binSearch(int arr[], int low, int high, int key)
    {
        if(low == high){
            if(key == arr[low])
                return low+1;
            else
                return 0;
        }
        else
        {
            int mid = (low + high)/2;
            if(key == arr[mid])
                return mid+1;
            else if (key < arr[mid])
                return binSearch(arr, low, mid-1, key);
            else
                return binSearch(arr, mid+1, high, key);
        }
    }
};

int main()
{
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;

    // Make sure size is positive
    while (size <= 0) {
        cout<<"Invalid size. Please enter a positive integer: ";
        cin>>size;
    }

    int a[size];
    cout<<"Enter the elements of the array: "<<endl;
    for (int i=0 ; i<size ; i++)
        cin>>a[i];

    cout<<"The elements of the array are: "<<endl;
    for (int i=0 ; i<size ; i++)
        cout<<a[i]<<"\t";
    cout<<endl;

    int low = 0;
    int high = size-1;

    int key;
    cout<<"Enter the key element to searched: ";
    cin>>key;

    // Make sure key is within bounds of array
    while (key < a[low] || key > a[high]) {
        cout<<"Invalid key. Please enter a value between "<<a[low]<<" and "<<a[high]<<": ";
        cin>>key;
    }

    BinarySearch bs;
    int position = bs.binSearch(a, low, high, key);
    if(position == 0)
        cout<<"The key element is not found"<<endl;
    else
        cout<<"The key element is found at position: "<<position<<endl;
    return 0;
}
