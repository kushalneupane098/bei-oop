#include <iostream>
#include <string>
using namespace std;

struct Patient {
    string name;
    int age;
    string disease;
};

int main() {
    Patient patients[3];

    for (int i = 0; i < 3; i++) {
        cout << "Enter details for Patient " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> patients[i].name;
        cout << "Age: ";
        cin >> patients[i].age;
        cout << "Disease: ";
        cin >> patients[i].disease;
        cout << endl;
    }

    cout << "--------- Patient Records ---------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Patient " << i + 1 << ":" << endl;
        cout << "  Name   : " << patients[i].name << endl;
        cout << "  Age    : " << patients[i].age << endl;
        cout << "  Disease: " << patients[i].disease << endl;
        cout << endl;
    }

    return 0;
}
