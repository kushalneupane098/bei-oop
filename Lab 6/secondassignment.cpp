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
    /*
    Expected Output:

    Constructor of A: 1
    Constructor of B: 2
    Constructor of C: 3
    Constructor of A: 4
    Constructor of B: 5
    Constructor of C: 6

    Destructor of C: 6
    Destructor of B: 5
    Destructor of A: 4
    Destructor of C: 3
    Destructor of B: 2
    Destructor of A: 1
    */

    C obj1(1, 2, 3);
    C obj2(4, 5, 6);

    return 0;
}