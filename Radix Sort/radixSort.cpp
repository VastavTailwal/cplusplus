#include<iostream>
#include<array>
#include<queue>
using namespace std;


void radixSort(int arr[], int size)
{
    array<queue<int>, 10> radix;
    int max = arr[0];
    for(int i = 1; i < size; ++i)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    for(int p = 1; p <= max; p *= 10)
    {
        for(int i = 0; i < size; ++i)
        {
            radix[(arr[i] / p) % 10].push(arr[i]);
        }
        int j = 0;
        for(auto element : radix)
        {
            while(!element.empty())
            {
                arr[j++] = element.front();
                element.pop();
            }
        }
    }
}


int main()
{
    int arr[] = {1,21,4,12,53,68,32,44,37,4,24};
    radixSort(arr, 11);
    for(int i = 0; i < 11; ++i)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}