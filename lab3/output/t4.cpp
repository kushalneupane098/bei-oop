#include <iostream>
using namespace std;

class Department {
private:
    int deptID;
    string deptName;

public:
    Department(int id, string name) {
        deptID = id;
        deptName = name;
        cout << "Constructor: " << deptName
             << " created" << endl;
    }

    ~Department() {
        cout << "Destructor: "
             << deptName
             << " going out of scope" << endl;
    }
};

int main() {

    Department d1(1, "Computer");

    {
        Department d2(2, "Civil");

        {
            Department d3(3, "Electrical");
        }

    }

    return 0;
}