#include<iostream>
using namespace std;


int partition(int arr[], int low, int high)
{
    int pivot = low;
    int i = low, j = high;
    while(i < j)
    {
        while(arr[i] <= arr[pivot]) ++i;
        while(arr[j] > arr[pivot]) --j;
        if(i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[pivot]);
    return j;
}


void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}


int main()
{
    int arr[] = {1,21,4,12,53,68,32,44,37,4,24};
    quickSort(arr, 0, 10);
    for(int i = 0; i < 11; ++i)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}