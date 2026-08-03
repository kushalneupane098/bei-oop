/*
Question 3:
Read and write information of 3 students in a file.
Also modify a student's information according to a given roll number.
*/

#include <iostream>
#include <fstream>
using namespace std;

class Student {
private:
    int roll;
    char name[30];
    float marks;

public:
    void input() {
        cout << "Enter roll number: ";
        cin >> roll;

        cout << "Enter name: ";
        cin.ignore();
        cin.getline(name, 30);

        cout << "Enter marks: ";
        cin >> marks;
    }

    void display() const {
        cout << "Roll: " << roll
             << ", Name: " << name
             << ", Marks: " << marks << endl;
    }

    int getRoll() const {
        return roll;
    }
};

int main() {
    Student s;

    ofstream outFile("students.dat", ios::binary);

    cout << "Enter details of 3 students:" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "\nStudent " << i + 1 << ":" << endl;
        s.input();
        outFile.write((char*)&s, sizeof(s));
    }

    outFile.close();

    int searchRoll;
    bool found = false;

    cout << "\nEnter roll number to modify: ";
    cin >> searchRoll;

    fstream file("students.dat", ios::binary | ios::in | ios::out);

    while (file.read((char*)&s, sizeof(s))) {
        if (s.getRoll() == searchRoll) {
            cout << "Enter new details:" << endl;
            s.input();

            file.seekp(-static_cast<int>(sizeof(s)), ios::cur);
            file.write((char*)&s, sizeof(s));

            found = true;
            break;
        }
    }

    file.close();

    if (found)
        cout << "Record modified successfully." << endl;
    else
        cout << "Record not found." << endl;

    ifstream inFile("students.dat", ios::binary);

    cout << "\nUpdated Records:" << endl;

    while (inFile.read((char*)&s, sizeof(s))) {
        s.display();
    }

    inFile.close();

    return 0;
}