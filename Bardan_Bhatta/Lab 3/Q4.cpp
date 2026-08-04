#include <iostream>
#include <string>
using namespace std;

class Department {
private:
    int deptID;
    string deptName;

public:
    Department(int id, string name) {
        deptID = id;
        deptName = name;
        cout << "Constructor: [" << deptName << "] created" << endl;
    }

    ~Department() {
        cout << "Destructor: [" << deptName << "] going out of scope" << endl;
    }
};

int main() {
    cout << "=== Main Program Starts ===" << endl;

    Department d1(1, "Computer Engineering");

    {
        cout << "\n  Entering Local Block 1" << endl;
        Department d2(2, "Electronics Engineering");
        cout << "  Leaving Local Block 1" << endl;
    }

    {
        cout << "\n   Entering Local Block 2" << endl;
        Department d3(3, "Civil Engineering");
        cout << "  Leaving Local Block 2" << endl;
    }

    cout << "\n Main Program Ending " << endl;
    return 0;
}