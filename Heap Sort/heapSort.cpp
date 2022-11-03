#include<iostream>
using namespace std;


void insert(int A[], int n)
{
    int i = n;
    while(i > 1 && A[i] > A[i / 2])
    {
        swap(A[i], A[i / 2]);
        i = i / 2;
    }
}


void remove(int A[], int n)
{
    int first = A[1];
    A[1] = A[n];
    A[n] = first;
    int i = 1, j = i * 2;
    while(j < n - 1)
    {
        if(A[j] < A[j + 1])
        {
            ++j;
        }
        if(A[j] > A[i])
        {
            swap(A[i], A[j]);
            i = j;
            j = i * 2;
        }
        else
        {
            break;
        }
    }
}


void heapify(int A[], const int n, int i)
{
    int largest = i;
    int left = i * 2;
    int right = i * 2 + 1;
    while(left <= n && A[left] > A[largest])
    {
        largest = left;
    }
    while(right <= n && A[right] > A[largest])
    {
        largest = right;
    }
    if(largest != i)
    {
        swap(A[largest], A[i]);
        heapify(A, n, largest);
    }
}


int main()
{

                                                    // without heapify

    int A[] = {0, 21, 67, 5, 262, 2, 334, 43, 4, 34, 32};
    const int n = 10;
    for(int i = 2; i <= n; ++i)
    {
        insert(A, i);
    }
    cout<<"Normal Heap Creation :";
    for(int i = 1; i <= n; ++i)
    {
        cout<<A[i]<<"\t";
    }
    cout<<endl;
    for(int i = 10; i >= 1; --i)
    {
        remove(A, i);
    }
    cout<<"Heap Sort :";
    for(int i = 1; i <= n; ++i)
    {
        cout<<A[i]<<"\t";
    }
    cout<<endl;

                                                    // using heapify

    for(int i = n / 2; i >= 1; --i)
    {
        heapify(A, n, i);
    }
    cout<<"heapify heap creation :";
    for(int i = 1; i <= n; ++i)
    {
        cout<<A[i]<<"\t";
    }
    cout<<endl;
    cout<<"heap sort using heapify :";
    int size = n;
    for(int i = n; i >= 1; --i)
    {
        swap(A[1], A[size]);
        --size;
        heapify(A, size, 1);
    }
    for(int i = 1; i <= n; ++i)
    {
        cout<<A[i]<<"\t";
    }
    cout<<endl;
    return 0;
}