#include <iostream>
#include <string>

using namespace std;

class DivideByZeroException
{
public:
    string message() const
    {
        return "Math Error: Division by zero.";
    }
};

class NegativeDenominatorException
{
public:
    string message() const
    {
        return "Input Error: Denominator is negative.";
    }
};

int main()
{
    double num, den;
    cout << "Enter numerator: ";
    cin >> num;
    cout << "Enter denominator: ";
    cin >> den;

    try
    {
        if (den == 0)
        {
            throw DivideByZeroException();
        }
        if (den < 0)
        {
            throw NegativeDenominatorException();
        }
        if (num == 999)
        {
            throw 404;
        }

        cout << "Result: " << (num / den) << endl;
    }
    catch (const DivideByZeroException &e)
    {
        cout << e.message() << endl;
    }
    catch (const NegativeDenominatorException &e)
    {
        cout << e.message() << endl;
    }
    catch (...)
    {
        cout << "Unexpected error occurred." << endl;
    }

    return 0;
}