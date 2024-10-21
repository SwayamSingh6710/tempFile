#include <iostream>
#include <vector>
using namespace std;

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Pivot element
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++)
    {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot)
        {
            i++; // Increment the index of the smaller element
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]); // Move the pivot element to the correct position
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high); // Partitioning index
        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{

    int arr[] = {3, 10, 0, 7, 4, 1, 9, 14, 11, 15};
    // int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int low = 0;
    int high = sizeof(arr) / sizeof(arr[0]);
    int size = high;
    cout << "Unsorted array : ";
    printArr(arr, size);

    quickSort(arr, low, high - 1);
    cout << "Sorted array   : ";
    printArr(arr, size);

    return 0;
}