#include <iostream>
using namespace std;

class Department {
private:
    int id;
    string name;

public:
    Department(int i, string n) {
        id = i;
        name = n;
        cout << name << " created\n";
    }

    ~Department() {
        cout << name << " destroyed\n";
    }
};

int main() {
    cout << "Start\n";

    Department d1(1, "HR");

    {
        cout << "Block 1\n";
        Department d2(2, "IT");
        Department d3(3, "Finance");
        cout << "End Block 1\n";
    }

    {
        cout << "Block 2\n";
        Department d4(4, "Marketing");
        cout << "End Block 2\n";
    }

    cout << "End main\n";

    return 0;
}