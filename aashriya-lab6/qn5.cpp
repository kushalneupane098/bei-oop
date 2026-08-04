#include <iostream>
using namespace std;

class A
{
public:
    A(int x)
    {
        cout << "A Constructor: " << x << endl;
    }

    ~A()
    {
        cout << "A Destructor" << endl;
    }
};

class B : public A
{
public:
    B(int x, int y) : A(x)
    {
        cout << "B Constructor: " << y << endl;
    }

    ~B()
    {
        cout << "B Destructor" << endl;
    }
};

class C : public B
{
public:
    C(int x, int y, int z)
        : B(x, y)
    {
        cout << "C Constructor: " << z << endl;
    }

    ~C()
    {
        cout << "C Destructor" << endl;
    }
};

int main()
{
    C obj1(1, 2, 3);

    cout << endl;

    C obj2(10, 20, 30);

    return 0;
}

