#include <iostream>
using namespace std;

class Department
{
private:
    int deptID;
    string deptName;

public:
    Department(int id, string name)
    {
        deptID = id;
        deptName = name;
        cout << "Constructor: " << deptName << " created" << endl;
    }

    ~Department()
    {
        cout << "Destructor: " << deptName << " going out of scope" << endl;
    }
};

int main()
{
    Department d1(1, "CSE");

    {
        Department d2(2, "ECE");

        {
            Department d3(3, "ME");
        }
    }

    return 0;
}