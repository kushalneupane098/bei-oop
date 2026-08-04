#include <iostream>
using namespace std;

class Maths; 

class Physics {
private:
    int mark;

public:
    Physics(int m = 0) {
        mark = m;
    }

  
    friend int totalMarks(const Physics&, const Maths&);
    friend bool isDistinction(const Physics&, const Maths&);
};

class Maths {
private:
    int mark;

public:
    Maths(int m = 0) {
        mark = m;
    }

   
    friend int totalMarks(const Physics&, const Maths&);
    friend bool isDistinction(const Physics&, const Maths&);
};


int totalMarks(const Physics& p, const Maths& m) {
    return p.mark + m.mark;
}


bool isDistinction(const Physics& p, const Maths& m) {
    return totalMarks(p, m) >= 160;
}

int main() {
    int physicsMark, mathsMark;

    cout << "Enter Physics marks (out of 100): ";
    cin >> physicsMark;

    cout << "Enter Maths marks (out of 100): ";
    cin >> mathsMark;

    Physics p(physicsMark);
    Maths m(mathsMark);

    int total = totalMarks(p, m);

    cout << "\nTotal Marks = " << total << " / 200" << endl;

    if (isDistinction(p, m))
        cout << "Distinction Achieved!" << endl;
    else
        cout << "Distinction Not Achieved." << endl;

    return 0;
}