#include <iostream>
using namespace std;

class Maths;

class Physics {
private:
    int marks;

public:
    void readMarks() {
        cout << "Enter marks for Physics (out of 100): ";
        cin >> marks;
    }

    friend int totalMarks(const Physics& p, const Maths& m);
    friend bool isDistinction(const Physics& p, const Maths& m);
};

class Maths {
private:
    int marks;

public:
    void readMarks() {
        cout << "Enter marks for Maths (out of 100): ";
        cin >> marks;
    }

    friend int totalMarks(const Physics& p, const Maths& m);
    friend bool isDistinction(const Physics& p, const Maths& m);
};

int totalMarks(const Physics& p, const Maths& m) {
    return p.marks + m.marks; 
}

bool isDistinction(const Physics& p, const Maths& m) {
    return ((p.marks + m.marks) >= 160);
}

int main() {
    Physics physObj;
    Maths mathObj;

    cout << "Student Evaluation Input" << endl;
    physObj.readMarks();
    mathObj.readMarks();

    int overallScore = totalMarks(physObj, mathObj);
    cout << "Results Summary" << endl;
    cout << "Total Consolidated Marks: " << overallScore << " / 200" << endl;

    if (isDistinction(physObj, mathObj)) {
        cout << "Result Status: Distinction Achieved!" << endl;
    } else {
        cout << "Result Status: Passed without Distinction." << endl;
    }

    return 0;
}