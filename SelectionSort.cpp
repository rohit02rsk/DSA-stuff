#include<bits/stdc++.h>
using namespace std;

void SelectionSort(int arr[], int n)
{
    for(int i=0 ; i<n ; ++i)
    {
        int least_index=i;
        for(int j=i+1; j<n ; ++j)
        {
            if(arr[j]<arr[least_index])
            {
                least_index=j;
            }
        }

        swap(arr[i], arr[least_index]);
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

    SelectionSort(input, size);

    cout<<"\nThe sorted array is:\n";
    for(int i=0 ; i<size ; ++i) cout<<input[i]<<" ";
    return 0;
}