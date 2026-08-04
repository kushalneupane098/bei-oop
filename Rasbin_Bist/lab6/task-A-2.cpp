#include <iostream>

using namespace std;

class A
{
private:
    int valA;

public:
    A(int a) : valA(a)
    {
        cout << "Constructor A: " << valA << endl;
    }

    ~A()
    {
        cout << "Destructor A: " << valA << endl;
    }
};

class B : public A
{
private:
    int valB;

public:
    B(int a, int b) : A(a), valB(b)
    {
        cout << "Constructor B: " << valB << endl;
    }

    ~B()
    {
        cout << "Destructor B: " << valB << endl;
    }
};

class C : public B
{
private:
    int valC;

public:
    C(int a, int b, int c) : B(a, b), valC(c)
    {
        cout << "Constructor C: " << valC << endl;
    }

    ~C()
    {
        cout << "Destructor C: " << valC << endl;
    }
};

int main()
{
    {
        C obj1(1, 2, 3);
        C obj2(10, 20, 30);
    }

    return 0;
}