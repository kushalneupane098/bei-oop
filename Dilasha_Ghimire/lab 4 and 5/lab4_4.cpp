#include <iostream>
using namespace std;

class Maths;

class Physics {
private:
    int mark;

public:
    Physics(int m) {
        mark = m;
    }

    friend int totalMarks(Physics, Maths);
    friend bool isDistinction(Physics, Maths);
};

class Maths {
private:
    int mark;

public:
    Maths(int m) {
        mark = m;
    }

    friend int totalMarks(Physics, Maths);
    friend bool isDistinction(Physics, Maths);
};

int totalMarks(Physics p, Maths m) {
    return p.mark + m.mark;
}

bool isDistinction(Physics p, Maths m) {
    return totalMarks(p, m) >= 160;
}

int main() {
    int pMark, mMark;

    cout << "Enter Physics Marks: ";
    cin >> pMark;

    cout << "Enter Maths Marks: ";
    cin >> mMark;

    Physics p(pMark);
    Maths m(mMark);

    cout << "Total Marks = "
         << totalMarks(p, m) << endl;

    if (isDistinction(p, m))
        cout << "Distinction Achieved";
    else
        cout << "No Distinction";

    return 0;
}