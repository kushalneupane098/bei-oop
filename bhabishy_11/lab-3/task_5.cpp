#include <iostream>

class StudentClass {
private:
    int *studentIDs;
    int size;

public:
    StudentClass(int n) {
        size = n;
        studentIDs = new int[size]; 
        
        std::cout << "Enter " << size << " student IDs:\n";
        for (int i = 0; i < size; ++i) {
            std::cout << "ID " << i + 1 << ": ";
            std::cin >> studentIDs[i];
        }
    }

    ~StudentClass() {
        delete[] studentIDs; 
        std::cout << "Memory freed.\n";
    }

    void display() const {
        std::cout << "Student IDs stored in heap array:\n";
        for (int i = 0; i < size; ++i) {
            std::cout << studentIDs[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    int numStudents;
    std::cout << "Enter number of students: ";
    std::cin >> numStudents;

    if (numStudents > 0) {
        StudentClass classGroup(numStudents);
        std::cout << "\n--- Displaying Data ---\n";
        classGroup.display();
        std::cout << "\n--- Ending Program Scope ---\n";
    } else {
        std::cout << "Invalid count.\n";
    }
system("pause");
    return 0;
}