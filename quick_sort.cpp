// CPP program to implement Quick Sort using OOP.

#include <iostream>
using namespace std;
// Define a class for the QuickSort algorithm
class QuickSort
{
private:
    // Define a method to partition the array around a pivot element
    int partition(int arr[], int low, int high)
    {
        int pivot = arr[high];  // Choose the last element as the pivot
        int i = low - 1;  // Index of the smaller element

        // Loop through the array and partition it around the pivot
        for (int j = low; j < high; j++)
        {
            // If the current element is smaller than or equal to the pivot,
            // swap it with the element at index i+1 and increment i
            if (arr[j] <= pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // Swap the pivot element with the element at index i+1
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        // Return the index of the pivot element
        return i + 1;
    }

    // Define a recursive method to perform QuickSort on the array
    void quickSort(int arr[], int low, int high)
    {
        // If the low index is less than the high index, there are still elements to be sorted
        if (low < high)
        {
            // Partition the array around a pivot element and get the pivot index
            int pivotIndex = partition(arr, low, high);

            // Recursively sort the elements on either side of the pivot
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

public:
    // Define a method to sort an array using QuickSort
    void sort(int arr[], int size)
    {
        // Call the recursive QuickSort method on the entire array
        quickSort(arr, 0, size - 1);
    }
};

int main()
{
    // Create an instance of the QuickSort class
    QuickSort qs;

    // Get the size of the array from the user
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // Create an array of the specified size
    // int* arr = new int[size];
    int arr[size];

    // Get the elements of the array from the user
    cout << "Enter the elements of the array, separated by spaces: ";
    for (int i = 0; i < size; i++)
        cin>>arr[i];

    // Sort the array using QuickSort
    qs.sort(arr, size);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
