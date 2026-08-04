#include <iostream>
using namespace std;

class A {
private:
    int valueA;

public:
    A(int v) : valueA(v) {
        cout << "A constructor: value = " << valueA << endl;
    }

    ~A() {
        cout << "A destructor: value = " << valueA << endl;
    }
};

class B : public A {
private:
    int valueB;

public:
    // Explicitly calls parent (A) constructor
    B(int va, int vb) : A(va), valueB(vb) {
        cout << "B constructor: value = " << valueB << endl;
    }

    ~B() {
        cout << "B destructor: value = " << valueB << endl;
    }
};

class C : public B {
private:
    int valueC;

public:
    // Explicitly calls parent (B) constructor
    C(int va, int vb, int vc) : B(va, vb), valueC(vc) {
        cout << "C constructor: value = " << valueC << endl;
    }

    ~C() {
        cout << "C destructor: value = " << valueC << endl;
    }
};

int main() {
    cout << "--- Creating object c1 ---" << endl;
    C c1(1, 2, 3);

    cout << "\n--- Creating object c2 ---" << endl;
    C c2(10, 20, 30);

    cout << "\n--- End of main, destructors fire in reverse order ---" << endl;
    return 0;
}

/*
EXPECTED OUTPUT:

--- Creating object c1 ---
A constructor: value = 1
B constructor: value = 2
C constructor: value = 3

--- Creating object c2 ---
A constructor: value = 10
B constructor: value = 20
C constructor: value = 30

--- End of main, destructors fire in reverse order ---
C destructor: value = 30
B destructor: value = 20
A destructor: value = 10
C destructor: value = 3
B destructor: value = 2
A destructor: value = 1

Explanation:
- Constructors always run top-down (base class first, then each
  derived class in order): A -> B -> C.
- Destructors always run bottom-up, in exact reverse order of
  construction: C -> B -> A.
- Because c1 and c2 are both local variables created in main(),
  they are destroyed in REVERSE order of creation when main() ends,
  so c2's destructor chain (C->B->A) runs completely before c1's.
*/
