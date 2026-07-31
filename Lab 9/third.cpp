#include <iostream>
using namespace std;

class DivideByZeroException
{
public:
    string message()
    {
        return "Division by Zero is not possible";
    }
};

class NegativeDenominatorException
{
public:
    string message()
    {
        return "Negative Denominator";
    }
};

int main()
{
    int a,b;

    cout<<"Enter numerator and denominator: ";
    cin>>a>>b;

    try
    {
        if(b==0)
            throw DivideByZeroException();

        if(b<0)
            throw NegativeDenominatorException();

        cout<<"Result = "<<a/b<<endl;
    }

    catch(DivideByZeroException e)
    {
        cout<<e.message()<<endl;
    }

    catch(NegativeDenominatorException e)
    {
        cout<<e.message()<<endl;
    }

    catch(...)
    {
        cout<<"Unknown Exception"<<endl;
    }

    return 0;
}