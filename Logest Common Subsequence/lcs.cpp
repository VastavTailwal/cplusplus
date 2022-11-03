#include<iostream>
#include<string>
using namespace std;


const string string1 = "ABKAKEJBKA";
const string string2 = "KJKASB";
int len1 = string1.length();
int len2 = string2.length();


void printLCS(int temp[][], char dirtemp[][], string str1, int i, int j)
{
    if(i == 0 || j == 0)
    {
        return;
    }
    if(dirtemp[i][j] == 'd')
    {
        printLCS(temp, dirtemp, str1, i - 1, j - 1);
        cout<<str1[i - 1];
    }
    else if(dirtemp[i][j] == 'u')
    {
        printLCS(temp, dirtemp, str1, i - 1, j);
    }
    else
    {
        printLCS(temp, dirtemp, str1, i, j - 1);
    }
}

int longestCommonSub(string str1, string str2)
{
    int m = str1.length();
    int n = str2.length();
    int dp[m + 1][n + 1];
    char dir[m + 1][n + 1];
    for(int i = 0; i <= m; ++i)
    {
        dp[i][0] = 0;
    }
    for(int j = 0; j <= n; ++j)
    {
        dp[0][j] = 0;
    }
    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                dir[i][j] = 'd';
            }
            else
            {
                if(dp[i - 1][j] >= dp[i][j - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                    dir[i][j] = 'u';
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                    dir[i][j] = 'l';
                }
            }
        }
    }
    cout<<dp[m][n]<<endl;
    printLCS(dp, dir, str1, m, n);
}


int main()
{
    longestCommonSub(string1, string2);
    return 0;
}