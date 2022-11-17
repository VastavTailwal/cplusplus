#include<iostream>
using namespace std;


class Act
{
    public:
    char act;
    unsigned short int start;
    unsigned short int end;
};


void selectActivity(Act activities[], const unsigned short int size)
{
    int i = 0, j = 1;
    cout<<"Activities order : ";
    cout<<activities[0].act<<"\t";
    while(j < size)
    {
        if(activities[i].end <= activities[j].start)
        {
            i = j;
            cout<<activities[i].act<<"\t";
        }
        else
        {
            ++j;
        }
    }
}


int main()
{
    unsigned short int n;
    cout<<"enter number of activities :";
    cin>>n;
    Act activities[n];
    for(int i = 0; i < n; ++i)
    {
        cin>>activities[i].act>>activities[i].start>>activities[i].end;
    }
    selectActivity(activities, n);
    return 0;
}