#include <bits\stdc++.h>
using namespace std;

int SequentialSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == key)
            return i;
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

    int flag = SequentialSearch(input, size, key);

    if (flag == -1)
        cout << "Element not in array.\n";
    else
        cout << "Element is found at " << flag + 1 << " position";
    return 0;
}