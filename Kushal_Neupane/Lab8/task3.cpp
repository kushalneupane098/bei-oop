#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
    int roll;
    char name[30];
    float marks;

public:
    void input() {
        cout << "Enter Roll: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 30);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() const {
        cout << "Roll: " << roll << " | Name: " << name << " | Marks: " << marks << endl;
    }

    int getRoll() const { return roll; }

    void writeToFile(ofstream &fout) {
        fout.write((char*)this, sizeof(Student));
    }

    void readFromFile(ifstream &fin) {
        fin.read((char*)this, sizeof(Student));
    }
};

int main() {
    Student s;
    ofstream fout("students.dat", ios::binary);
    for (int i = 0; i < 10; i++) {
        cout << "\nEnter details for student " << i + 1 << endl;
        s.input();
        s.writeToFile(fout);
    }
    fout.close();

    // Modify student info by roll number
    int rollToModify;
    cout << "\nEnter roll number to modify: ";
    cin >> rollToModify;

    fstream file("students.dat", ios::in | ios::out | ios::binary);
    while (file.read((char*)&s, sizeof(Student))) {
        if (s.getRoll() == rollToModify) {
            cout << "Enter new details:\n";
            s.input();
            file.seekp(-sizeof(Student), ios::cur);
            file.write((char*)&s, sizeof(Student));
            cout << "Record updated successfully!\n";
            break;
        }
    }
    file.close();

    // Display all students
    ifstream fin("students.dat", ios::binary);
    cout << "\n=== Student Records ===\n";
    while (fin.read((char*)&s, sizeof(Student))) {
        s.display();
    }
    fin.close();

    return 0;
}


