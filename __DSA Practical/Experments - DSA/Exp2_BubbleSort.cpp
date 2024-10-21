#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[j] > arr[j + 1] && j < size - 1)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubbleSort(vector<int> &arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[j] > arr[j + 1] && j < size - 1)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}
void printArr(vector<int> &arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}

int main()
{

    // int arr[] = {3, 10, 0, 7, 4, 1, 9, 14, 11, 15};
    // int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    // int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> arr{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int size = arr.size();
    cout << "Unsorted array : ";
    printArr(arr, size);

    cout << "Sorted array   : ";
    bubbleSort(arr, size);
    printArr(arr, size);

    return 0;
}
