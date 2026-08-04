#include <iostream>
using namespace std;

class A
{
protected:
    int a;

public:
    A(int x)
    {
        a = x;
        cout << "Constructor of A: " << a << endl;
    }

    ~A()
    {
        cout << "Destructor of A: " << a << endl;
    }
};

class B : public A
{
protected:
    int b;

public:
    B(int x, int y) : A(x)
    {
        b = y;
        cout << "Constructor of B: " << b << endl;
    }

    ~B()
    {
        cout << "Destructor of B: " << b << endl;
    }
};

class C : public B
{
private:
    int c;

public:
    C(int x, int y, int z) : B(x, y)
    {
        c = z;
        cout << "Constructor of C: " << c << endl;
    }

    ~C()
    {
        cout << "Destructor of C: " << c << endl;
    }
};

int main()
{

    C obj1(10, 20, 30);
    C obj2(40, 50, 60);

    return 0;
}