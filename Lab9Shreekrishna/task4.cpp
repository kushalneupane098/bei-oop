#include <iostream>
#include <stdexcept>
using namespace std;

void compute(int a, int b)
{
    try
    {
        if (b == 0)
            throw runtime_error("Division by zero");

        cout << "Result = " << a / b << endl;
    }
    catch (runtime_error &e)
    {
        cout << "compute() caught: " << e.what() << endl;
        throw;
    }
}

int main()
{
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    try
    {
        compute(a, b);
    }
    catch (runtime_error &e)
    {
        cout << "main() caught: " << e.what() << endl;
    }

    return 0;
}