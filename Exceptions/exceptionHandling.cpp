#include<iostream>
#include<stdexcept>                                 // class derived from `std::Exception` class
using namespace std;

float divide(const int num1, const int num2)
{
    if(num2 == 0)
    {
        throw runtime_error("divide by 0 error\n"); // using and not using `throw` gives different result
    }
    else
    {
        return num1 / num2;
    }
}

int main()
{
    int a = 90, b = 0;
    try
    {
        cout<<divide(a, b);
    }
    catch(runtime_error &run)
    {
        cout<<"exception occured\n";
        cout<<run.what();
    }
    catch(...)
    {
        cout<<"Anonymous error occured";
    }
    return 0;
}