#include <iostream>
using namespace std;

class StudentClass {
private:
    int* ptr;
    int size;

public:
    StudentClass(int n) {
        size = n;
        ptr = new int[size];
        cout << "Dynamic constructor: Allocated memory for " << size << " student IDs on heap." << endl;
    }

    ~StudentClass() {
        delete[] ptr;
        cout << "Memory freed" << endl;
    }

    void readIDs() {
        cout << "Enter " << size << " student IDs:" << endl;
        for (int i = 0; i < size; i++) {
            cout << "ID [" << i + 1 << "]: ";
            cin >> ptr[i];
        }
    }

    void display() const {
        cout << "Stored Student IDs: ";
        for (int i = 0; i < size; i++) {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int num;
    cout << "Enter total number of students: ";
    cin >> num;

    StudentClass batch(num);

    batch.readIDs();
    batch.display();

    return 0;
}