#include <iostream>
using namespace std;

class DivideByZeroException
{
public:
    const char *message()
    {
        return "Division by zero is not allowed.";
    }
};

class NegativeDenominatorException
{
public:
    const char *message()
    {
        return "Negative denominator is not allowed.";
    }
};

int main()
{
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    try
    {
        if (b == 0)
            throw DivideByZeroException();

        if (b < 0)
            throw NegativeDenominatorException();

        cout << "Result = " << (float)a / b << endl;
    }
    catch (DivideByZeroException e)
    {
        cout << e.message() << endl;
    }
    catch (NegativeDenominatorException e)
    {
        cout << e.message() << endl;
    }
    catch (...)
    {
        cout << "Unexpected exception occurred." << endl;
    }

    return 0;
}