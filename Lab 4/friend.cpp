#include <iostream>
using namespace std;

class Maths;

class Physics
{
private:
    int marks;

public:
    Physics(int m)
    {
        marks = m;
    }

    friend int totalMarks(Physics, Maths);
};

class Maths
{
private:
    int marks;

public:
    Maths(int m)
    {
        marks = m;
    }

    friend int totalMarks(Physics, Maths);
};

int totalMarks(Physics p, Maths m)
{
    return p.marks + m.marks;
}

int main()
{
    int physicsMarks, mathsMarks;

    cout << "Enter Physics Marks: ";
    cin >> physicsMarks;

    cout << "Enter Maths Marks: ";
    cin >> mathsMarks;

    Physics physics(physicsMarks);
    Maths maths(mathsMarks);

    int total = totalMarks(physics, maths);

    cout << "Total Marks = " << total << endl;

    if (total >= 160)
        cout << "Distinction";
    else
        cout << "No Distinction";

    return 0;
}