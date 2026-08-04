#include <iostream>
using namespace std;

class StudentClass {
private:
    int *id;
    int n;

public:
    StudentClass(int x) {
        n = x;
        id = new int[n];
        cout << "Memory allocated for " << n << " students\n";
    }

    ~StudentClass() {
        delete[] id;
        cout << "Memory freed\n";
    }

    void read() {
        cout << "Enter IDs:\n";
        for (int i = 0; i < n; i++) {
            cin >> id[i];
        }
    }

    void show() {
        cout << "Student IDs: ";
        for (int i = 0; i < n; i++) {
            cout << id[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    StudentClass s(n);

    s.read();
    s.show();

    cout << "End\n";

    return 0;
}