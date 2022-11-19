#include<iostream>
using namespace std;


class Act
{
    public:
    char act;
    unsigned short int start;
    unsigned short int end;

    friend istream& operator >>(istream&, Act&);
    friend ostream& operator >>(ostream&, Act&);
};


istream& operator >>(istream& in, Act& Activity)
{
    in>>Activity.act>>Activity.start>>Activity.end;
    return in;
}


ostream& operator <<(ostream& out, Act& Activity)
{
    out<<Activity.act;
    return out;
}


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
            cout<<activities[i]<<"\t";
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
        cin>>activities[i];
    }
    selectActivity(activities, n);
    return 0;
}