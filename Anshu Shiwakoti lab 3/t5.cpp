#include <iostream>
using namespace std;

class StudentClass
{
private:
    int *id;
    int size;

public:
    StudentClass(int n)
    {
        size = n;
        id = new int[size];

        cout << "Enter Student IDs: ";
        for (int i = 0; i < size; i++)
            cin >> id[i];
    }

    void display()
    {
        cout << "Student IDs: ";
        for (int i = 0; i < size; i++)
            cout << id[i] << " ";
        cout << endl;
    }

    ~StudentClass()
    {
        delete[] id;
        cout << "Memory freed!" << endl;
    }
};

int main()
{
    int n;

    cout << "Enter number of students: ";

    if (!(cin >> n) || n <= 0)
    {
        cout << "Invalid number of students." << endl;
        return 0;
    }

    StudentClass s(n);
    s.display();

    return 0;
}