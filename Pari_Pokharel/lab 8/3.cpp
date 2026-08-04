#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int rollNo;
    char name[20];
    float marks;
};

int main() {
    fstream file("student.dat", ios::in | ios::out | ios::binary | ios::trunc);
    Student s;

    for (int i = 1; i <= 10; i++) {
        s.rollNo = i;
        cout << "Enter name and marks for Roll " << i << ": ";
        cin >> s.name >> s.marks;
        file.write(reinterpret_cast<char*>(&s), sizeof(Student));
    }

    int r;
    cout << "\nEnter Roll Number to modify: ";
    cin >> r;

    file.seekg((r - 1) * sizeof(Student));
    file.read(reinterpret_cast<char*>(&s), sizeof(Student));

    cout << "Enter new name and marks: ";
    cin >> s.name >> s.marks;

    file.seekp((r - 1) * sizeof(Student));
    file.write(reinterpret_cast<char*>(&s), sizeof(Student));

    file.close();
    return 0;
}