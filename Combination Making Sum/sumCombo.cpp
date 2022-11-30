#include<iostream>
using namespace std;


int count(const int arr[], const int size, int sum, int index)
{
    if(index == size)
    {
        if(sum == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int l = 0;
    if(arr[index] <= sum)
    {
        l = count(arr, size, sum - arr[index], index);
    }
    int r = count(arr, size, sum, index + 1);
    return l + r;
}


int countComboMakingSum(const int num)
{
    int arr[num];
    const int size = num;
    for(int i = 0; i < num; ++i)
    {
        arr[i] = i + 1;
    }
    return count(arr, size, num, 0);
}


int main()
{
    int num = 5;
    cout<<countComboMakingSum(num);
    return 0;
}