#include <iostream>

using namespace std;

class Employee {
public:
    virtual float calculateSalary() = 0;
    virtual void display() = 0;
    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
private:
    float monthlySalary;
public:
    FullTimeEmployee(float salary) : monthlySalary(salary) {}
    float calculateSalary() override { return monthlySalary; }
    void display() override {
        cout << "FullTime Salary: " << calculateSalary() << endl;
    }
};

class PartTimeEmployee : public Employee {
private:
    float hoursWorked;
    float hourlyRate;
public:
    PartTimeEmployee(float hours, float rate) : hoursWorked(hours), hourlyRate(rate) {}
    float calculateSalary() override { return hoursWorked * hourlyRate; }
    void display() override {
        cout << "PartTime Salary: " << calculateSalary() << endl;
    }
};

class Contractor : public Employee {
private:
    float projectFee;
    float taxRate;
public:
    Contractor(float fee, float tax) : projectFee(fee), taxRate(tax) {}
    float calculateSalary() override { return projectFee - (projectFee * taxRate); }
    void display() override {
        cout << "Contractor Salary: " << calculateSalary() << endl;
    }
};

int main() {
    Employee* workforce[3];
    workforce[0] = new FullTimeEmployee(5000.0f);
    workforce[1] = new PartTimeEmployee(80.0f, 25.0f);
    workforce[2] = new Contractor(4000.0f, 0.15f);

    for (int i = 0; i < 3; ++i) {
        workforce[i]->display();
    }

    for (int i = 0; i < 3; ++i) {
        delete workforce[i];
    }

    return 0;
}