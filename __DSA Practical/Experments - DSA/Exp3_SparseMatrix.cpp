#include <iostream>
using namespace std;

int main()
{
    int cols;
    int rows;

    cout << "Enter no. of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    int arr[rows][cols];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter value at (" << i + 1 << "," << j + 1 << "): ";
            cin >> arr[i][j];
        }
    }

    cout << "\nOriginal matrix:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // create sparse matrix

    // check for non zero elements
    int size = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] != 0)
            {
                size++;
            }
        }
    }

    int sparseMatrix[3][size];
    int k = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] != 0)
            {
                sparseMatrix[0][k] = i;
                sparseMatrix[1][k] = j;
                sparseMatrix[2][k] = arr[i][j];
                k++;
            }
        }
    }

    cout << "\nSparse matrix:" << endl;
    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            cout << "R : ";
        }
        if (i == 1)
        {
            cout << "C : ";
        }
        if (i == 2)
        {
            cout << "V : ";
        }
        for (int j = 0; j < size; j++)
        {
            cout << sparseMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // transpose the sparse matrix
    int transposeSparseMatrix[3][size];
    for (int i = 0; i < 3; i++)
    {
        if (i == 2)
        {
            for (int j = 0; j < size; j++)
            {
                transposeSparseMatrix[i][j] = sparseMatrix[i][j];
            }
        }
        else
        {
            for (int j = 0; j < size; j++)
            {
                transposeSparseMatrix[0][j] = sparseMatrix[1][j];
                transposeSparseMatrix[1][j] = sparseMatrix[0][j];
            }
        }
    }

    cout << "\nTranspose Sparse matrix:" << endl;
    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            cout << "R : ";
        }
        if (i == 1)
        {
            cout << "C : ";
        }
        if (i == 2)
        {
            cout << "V : ";
        }
        for (int j = 0; j < size; j++)
        {
            cout << transposeSparseMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}