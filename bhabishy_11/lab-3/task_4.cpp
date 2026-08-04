#include <iostream>
#include <string>

class Department {
private:
    std::string deptName;
    int deptID;

public:
    Department(int id, std::string name) {
        deptID = id;
        deptName = name;
        std::cout << "Constructor: [" << deptName << "] created\n";
    }

    ~Department() {
        std::cout << "Destructor: [" << deptName << "] going out of scope\n";
    }
};

int main() {
    std::cout << "Entering main()\n";
    
    Department d1(1, "HR");
    
    {
        std::cout << "  Entering Block A\n";
        Department d2(2, "IT");
        std::cout << "  Exiting Block A\n";
    } 

    {
        std::cout << "  Entering Block B\n";
        Department d3(3, "Finance");
        std::cout << "  Exiting Block B\n";
    } 

    std::cout << "Exiting main()\n";
    system("pause");    
    return 0;
} 