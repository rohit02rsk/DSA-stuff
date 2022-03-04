#include<bits/stdc++.h>
using namespace std;

void BubbleSort(int arr[], int n)
{
    int swapped;
    for(int i=0 ; i<n ; ++i)
    {
        swapped=0;

        for(int j=0 ; j<n-i-1 ; ++j)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = 1;
            }
        }

        if(swapped==0)
        break;
    }
}

int main()
{
    int size;

    printf("Enter the size of your array:\n");
    scanf("%d", &size);

    int input[size];
    printf("Enter your array:\n");
    for(int i=0 ; i<size ; ++i) scanf("%d", &input[i]);

    BubbleSort(input, size);

    cout<<"\nThe sorted array is:\n";
    for(int i=0 ; i<size ; ++i) printf("%d ", input[i]);

    return 0;
}