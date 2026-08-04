#include <iostream>
using namespace std;

class StudentClass {
public:
    int* ids;
    int size;

    StudentClass(int n) {
        size = n;
        ids = new int[n];
        cout << "Enter " << n << " student IDs:\n";
        for (int i = 0; i < n; i++) {
            cin >> ids[i];
        }
    }

       void display() {
        cout << "Student IDs: ";
        for (int i = 0; i < size; i++) {
            cout << ids[i] << " ";
        }
        cout << endl;
    }

      ~StudentClass() {
        delete[] ids;
        cout << "Memory freed\n";
    }
};

int main() {
    int n;
    cout << "How many students? ";
    cin >> n;

    StudentClass s(n);
    s.display();

    return 0;
}