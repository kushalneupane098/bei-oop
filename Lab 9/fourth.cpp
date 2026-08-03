#include <iostream>
using namespace std;

void compute(int a,int b)
{
    try
    {
        if(b==0)
            throw "Division by Zero";

        cout<<"Result = "<<a/b<<endl;
    }

    catch(const char *msg)
    {
        cout<<"Exception caught inside compute(): "<<msg<<endl;
        throw;
    }
}

int main()
{
    try
    {
        compute(10,0);
    }

    catch(const char *msg)
    {
        cout<<"Exception caught in main(): "<<msg<<endl;
    }

    return 0;
}