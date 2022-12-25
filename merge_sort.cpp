// CPP program to implement Merge Sort using OOP.

#include <iostream>
using namespace std;

class MergeSort
{
private:
    // A function to merge the two half into a sorted data.
    void merge(int *a, int low, int high, int mid)
    {
        // We have low to mid and mid+1 to high already sorted.
        int i, j, k, temp[high-low+1];
        i = low;
        k = 0;
        j = mid + 1;

        // Merge the two parts into temp[].
        while (i <= mid && j <= high)
        {
            if (a[i] < a[j])
            {
                temp[k] = a[i];
                k++;
                i++;
            }
            else
            {
                temp[k] = a[j];
                k++;
                j++;
            }
        }

        // Insert all the remaining values from i to mid into temp[].
        while (i <= mid)
        {
            temp[k] = a[i];
            k++;
            i++;
        }

        // Insert all the remaining values from j to high into temp[].
        while (j <= high)
        {
            temp[k] = a[j];
            k++;
            j++;
        }


        // Assign sorted data stored in temp[] to a[].
        for (i = low; i <= high; i++)
        {
            a[i] = temp[i-low];
        }
    }

    // A function to split array into two parts.
    void mergeSort(int *a, int low, int high)
    {
        int mid;
        if (low < high)
        {
            mid=(low+high)/2;
            // Split the data into two half.
            mergeSort(a, mid+1, high);
            mergeSort(a, low, mid);

            // Merge them to get sorted output.
            merge(a, low, high, mid);
        }
    }

public:
    void sort(int *a, int n)
    {
        mergeSort(a, 0, n-1);
    }
};

int main()
{
    int n, i;
    cout << "\nEnter the number of data elements to be sorted: ";
    cin >> n;

    int arr[n];
    for (i = 0; i < n; i++)
    {
        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
    }

    MergeSort sorter;
    sorter.sort(arr, n);

    // Printing the sorted data.
    cout << "\nSorted Data ";
    for (i = 0; i < n; i++)
        cout << "->" << arr[i];

    return 0;
}
