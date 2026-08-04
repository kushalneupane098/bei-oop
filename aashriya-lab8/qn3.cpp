#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int roll;
    char name[30];
    float marks;
};

int main() {
    Student s;

    fstream file("students.dat", ios::binary | ios::out);

    cout << "Enter information of 10 students:\n";

    for(int i = 0; i < 10; i++) {
        cout << "\nRoll: ";
        cin >> s.roll;

        cout << "Name: ";
        cin >> s.name;

        cout << "Marks: ";
        cin >> s.marks;

        file.write((char*)&s, sizeof(Student));
    }

    file.close();

    int searchRoll;
    cout << "\nEnter roll number to modify: ";
    cin >> searchRoll;

    file.open("students.dat",
              ios::binary | ios::in | ios::out);

    while(file.read((char*)&s, sizeof(Student))) {
        if(s.roll == searchRoll) {

            cout << "\nNew Name: ";
            cin >> s.name;

            cout << "New Marks: ";
            cin >> s.marks;

            file.seekp(-sizeof(Student), ios::cur);

            file.write((char*)&s, sizeof(Student));

            cout << "Record Updated.\n";
            break;
        }
    }

    file.close();

    return 0;
}