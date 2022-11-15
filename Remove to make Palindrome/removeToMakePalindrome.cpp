#include<iostream>
#include<string>
using namespace std;


char removeToMakePal(string given)
{
    string s1 = "";
    string s2 = "";
    int i, j, k;
    for(i = 0; i < given.length(); ++i)
    {
        for(j = 0; j < given.length(); ++j)
        {
            if(i != j)
            {
                s1 = s1 + given[j];
            }
        }
        for(k = s1.length() - 1; k >= 0; --k)
        {
            s2 = s2 + s1[k];
        }
        if(s1.compare(s2) == 0)
        {
            break;
        }
        s1 = "";
        s2 = "";
    }
    return given[i];
}


int main()
{
    string given = "1233621";
    cout<<removeToMakePal(given);
    return 0;
}