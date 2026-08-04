#include <iostream>
using namespace std;

class A {
protected:
    int a;

public:
    A(int x) {
        a = x;
        cout << "Constructor A: " << a << endl;
    }

    ~A() {
        cout << "Destructor A: " << a << endl;
    }
};

class B : public A {
protected:
    int b;

public:
    B(int x, int y) : A(x) {
        b = y;
        cout << "Constructor B: " << b << endl;
    }

    ~B() {
        cout << "Destructor B: " << b << endl;
    }
};

class C : public B {
private:
    int c;

public:
    C(int x, int y, int z)
        : B(x, y) {
        c = z;
        cout << "Constructor C: " << c << endl;
    }

    ~C() {
        cout << "Destructor C: " << c << endl;
    }
};

int main() {

    C obj1(1, 2, 3);
    cout << endl;

    C obj2(10, 20, 30);

    return 0;
}

