#include<bits\stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int t=*b;
    *b=*a;
    *a=t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1); 
 
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int Pindex = partition(arr, low, high);
 
        QuickSort(arr, low, Pindex - 1);
        QuickSort(arr, Pindex + 1, high);
    }
}

int main()
{
    int size;

    cout<<"Enter the size of your array:\n";
    cin>>size;

    int input[size];
    cout<<"Enter your array:\n";
    for(int i=0 ; i<size ; ++i) cin>>input[i];

    QuickSort(input, 0, size-1);

    cout<<"\nThe sorted array is:\n";
    for(int i=0 ; i<size ; ++i) cout<<input[i]<<" ";
    return 0;
}