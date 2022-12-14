// CPP program to implement Linear Search Algorithm

#include <iostream>
using namespace std;

void linearSearch(int a[], int n, int key)
{
    int flag=0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            flag = 1;
            cout<<"Element found at position: " << i + 1 << endl;
            cout<<"Search is successful.";
        }
    }
    if (flag == 0)
    {
        cout<<"No Element Found. Search unsuccessful." << endl;
    }
}
// main function
int main()
{
    int arr[10], n;
    cout<<"enter the total number of elements: ";
    cin>>n;
    cout << "Please enter the elements of the Array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Please enter an element to search" << endl;
    int key;
    cin >> key;
    linearSearch(arr, n, key);
    return 0;
}