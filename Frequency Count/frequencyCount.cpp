#include<iostream>
using namespace std;


// stable means frequency of each digit is same else the number is unstable
bool isStable(int num)
{
    int i;
    int hash[10] = {0};
    while(num > 0)
    {
        int digit = num % 10;
        ++hash[digit];
        num /= 10;
    }
    for(i = 0; hash[i] == 0; ++i);
    for(int j = i; j < 10; ++j)
    {
        if(hash[j] > 0 && hash[i] != hash[j])
        {
            return false;
        }
    }
    return true;
}


int main()
{
    int nums[] = {12, 1313, 122, 678, 898};
    int sum = 0;
    int size = sizeof(nums) / sizeof(nums[0]);
    for(int i = 0; i < size; ++i)
    {
        if(isStable(nums[i]))
        {
            sum += nums[i];
        }
        else
        {
            sum -= nums[i];
        }
    }
    cout<<"Password :"<<sum;
    return 0;
}