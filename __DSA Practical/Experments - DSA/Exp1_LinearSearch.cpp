#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 11;

    int ans = linearSearch(arr, size, key);
    if (ans != -1)
    {
        cout << "Element found at : " << ans << endl;
    }
    else
    {
        cout << "Element not found " << endl;
    }

    return 0;
}