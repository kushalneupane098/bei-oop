#include <iostream>
using namespace std;

class A {
private:
    int x;

public:
    A(int x) : x(x) {
        cout << "Constructor A: x = " << x << endl;
    }

    ~A() {
        cout << "Destructor A: x = " << x << endl;
    }
};

class B : public A {
private:
    int y;

public:
    B(int x, int y) : A(x), y(y) {
        cout << "Constructor B: y = " << y << endl;
    }

    ~B() {
        cout << "Destructor B: y = " << y << endl;
    }
};

class C : public B {
private:
    int z;

public:
    C(int x, int y, int z) : B(x, y), z(z) {
        cout << "Constructor C: z = " << z << endl;
    }

    ~C() {
        cout << "Destructor C: z = " << z << endl;
    }
};

int main() {
    C obj1(1, 2, 3);
    cout << endl;
    C obj2(4, 5, 6);
    cout << endl;
}
