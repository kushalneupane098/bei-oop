#include <iostream>
using namespace std;

class StudentClass {
private:
    int *marks;
    int size;

public:
    StudentClass(int n) {
        size = n;
        marks = new int[size];

        cout << "Enter " << size << " IDs:\n";

        for(int i = 0; i < size; i++) {
            cin >> marks[i];
        }
    }

    void display() {
        cout << "Student IDs:\n";

        for(int i = 0; i < size; i++) {
            cout << marks[i] << " ";
        }

        cout << endl;
    }

    ~StudentClass() {
        delete[] marks;
        cout << "Memory freed" << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    StudentClass s(n);

    s.display();

    return 0;
}