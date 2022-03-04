#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int size;

    cout << "Enter the size of your array:\n";
    cin >> size;

    int input[size];
    cout << "Enter your array:\n";
    for (int i = 0; i < size; ++i)
        cin >> input[i];

    InsertionSort(input, size);

    cout << "\nThe sorted array is:\n";
    for (int i = 0; i < size; ++i)
        cout << input[i] << " ";
    return 0;
}