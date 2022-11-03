#include<iostream>
using namespace std;


void merge(int arr[], int low, int mid, int high)
{
    int temp[high + 1];
    int i = low, j = mid + 1, k = low;
    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    for(; i <= mid; ++i)
        temp[k++] = arr[i];
    for(; j <= high; ++j)
        temp[k++] = arr[j];
    for(i = low; i <= high; ++i)
        arr[i] = temp[i];
}


void mergeSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}


int main()
{
    int arr[] = {1,21,4,12,53,68,32,44,37,4,24};
    mergeSort(arr, 0, 10);
    for(int i = 0; i < 11; ++i)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}