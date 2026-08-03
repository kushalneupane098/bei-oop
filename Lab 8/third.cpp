#include <iostream>
#include <fstream>
using namespace std;

class Student
{
public:
    int roll;
    char name[30];
    float marks;

    void input()
    {
        cout << "Enter roll, name, marks: ";
        cin >> roll >> name >> marks;
    }

    void display()
    {
        cout << "Roll: " << roll << "\nName: " << name
             << "\nMarks: " << marks << endl;
    }
};

int main()
{
    Student s;
    fstream file;

    file.open("student.dat", ios::out | ios::binary);

    for(int i = 0; i < 10; i++)
    {
        s.input();
        file.write((char*)&s, sizeof(s));
    }

    file.close();

    int r;
    cout << "Enter roll number to modify: ";
    cin >> r;

    file.open("student.dat", ios::in | ios::out | ios::binary);

    while(file.read((char*)&s, sizeof(s)))
    {
        if(s.roll == r)
        {
            cout << "Enter new information:\n";
            s.input();

            file.seekp(-sizeof(s), ios::cur);
            file.write((char*)&s, sizeof(s));
            break;
        }
    }

    file.close();

    file.open("student.dat", ios::in | ios::binary);

    while(file.read((char*)&s, sizeof(s)))
    {
        s.display();
    }

    file.close();

    return 0;
}