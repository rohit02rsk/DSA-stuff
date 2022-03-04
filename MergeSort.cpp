#include<bits\stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int h)
{
    /* sizes of the left and right subarrays */
    int n1=m-l+1, n2=h-m; 
    int left[n1],right[n2];

    /* stroing the elements in the left and right subarrays */
    for(int i=0;i<n1;i++)
        left[i]=arr[i+l];

    for(int j=0;j<n2;j++)
        right[j]=arr[m+1+j];   

    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
            arr[k++]=left[i++];
        else
            arr[k++]=right[j++];
    }

    /* dealing with the rest of the elements */
    while(i<n1)
        arr[k++]=left[i++];
    while(j<n2)
        arr[k++]=right[j++];
}

void MergeSort(int arr[], int l, int r)
{
    /* executes only when size of array is greater than 1 */
    if(r>l)
    {
        int m=l+(r-l)/2;

        /* recursive call to sort the subarrays */
        MergeSort(arr,l,m);
        MergeSort(arr,m+1,r);

        merge(arr,l,m,r);
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

    MergeSort(input, 0, size-1);

    cout<<"\nThe sorted array is:\n";
    for(int i=0 ; i<size ; ++i) cout<<input[i]<<" ";
    return 0;
}