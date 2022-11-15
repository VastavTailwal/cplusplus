#include<iostream>
using namespace std;


int mcm(int A[], const int n)
{
    int dp[n][n];
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            dp[i][j] = 0;
        }
    }
    for(int diff = 2; diff < n; ++diff)
    {
        for(int i = 0, j = diff; i < n - diff; ++i, ++j)
        {
            dp[i][j] = INT32_MAX;
            for(int k = i + 1; k < j; ++k)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[k] * A[j]);
            }
        }
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }
    return dp[0][n - 1];
}


int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<mcm(arr, size);
    return 0;
}