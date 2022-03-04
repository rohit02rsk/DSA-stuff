#include <bits\stdc++.h>
using namespace std;

int BinarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        else if (arr[mid] > key)
            high = mid - 1;

        else
            low = mid + 1;
    }
    return -1;
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

    int key;
    cout << "Enter the element to be searched:\n";
    cin >> key;

    sort(input, input+size);

    int flag = BinarySearch(input, size, key);

    if (flag == -1)
        cout << "Element not in array.\n";
    else
        cout << "Element is found at " << flag + 1 << " position in the sorted array\n";
    return 0;
}