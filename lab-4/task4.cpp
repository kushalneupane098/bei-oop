#include <iostream>
using namespace std;

class Maths;

class Physics {
private:
    int marks;

public:
    Physics(int m) {
        marks = m;
    }

    friend int totalMarks(Physics, Maths);
};

class Maths {
private:
    int marks;

public:
    Maths(int m) {
        marks = m;
    }

    friend int totalMarks(Physics, Maths);
};

int totalMarks(Physics p, Maths m) {
    return p.marks + m.marks;
}

bool isDistinction(int total) {
    return (total >= 160 && total <= 200);
}

int main() {
    int pMarks, mMarks;

    cout << "Enter Physics Marks: ";
    cin >> pMarks;

    cout << "Enter Maths Marks: ";
    cin >> mMarks;

    Physics p(pMarks);
    Maths m(mMarks);

    int total = totalMarks(p, m);

    cout << "Total Marks = " << total << endl;

    if (isDistinction(total))
        cout << "Distinction Achieved\n";
    else
        cout << "No Distinction\n";

    return 0;
}