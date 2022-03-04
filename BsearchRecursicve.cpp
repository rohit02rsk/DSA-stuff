#include <bits\stdc++.h>
using namespace std;

int BinarySearch(int arr[], int low, int high, int key)
{
	if(low > high)
		return -1;

	int mid = (low + high) / 2;

	if(arr[mid] == key)
		return mid;

	else if(arr[mid] > key)
		return BinarySearch(arr, low, mid - 1, key);

	else
		return BinarySearch(arr, mid + 1, high, key);
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

    int flag = BinarySearch(input, 0, size-1, key);

    if (flag == -1)
        cout << "Element not in array.\n";
    else
        cout << "Element is found at " << flag + 1 << " position";
    return 0;
}