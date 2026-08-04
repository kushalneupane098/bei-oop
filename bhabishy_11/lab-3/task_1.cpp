#include <iostream>

class Box {
private:
    float l, b, h;

public:
    Box() {
        l = 0; b = 0; h = 0;
        std::cout << "Default constructor called.\n";
    }

    Box(float len, float bre, float hei) {
        l = len; b = bre; h = hei;
        std::cout << "Parameterized constructor called.\n";
    }

    Box(float len, float bre = 1.0f) {
        l = len; b = bre; h = 1.0f;
        std::cout << "Constructor with default arguments called.\n";
    }

    Box(const Box &other) {
        l = other.l;
        b = other.b;
        h = other.h;
        std::cout << "Copy constructor called.\n";
    }

    ~Box() {
        std::cout << "Destructor called: Object destroyed.\n";
    }
};

int main() {
    std::cout << "--- Creating b1 ---\n";
    Box b1; 
    
    std::cout << "\n--- Creating b2 ---\n";
    Box b2(5.5, 4.2, 3.0);
    
    std::cout << "\n--- Creating b3 ---\n";
    Box b3(10.5); 
    
    std::cout << "\n--- Creating b4 ---\n";
    Box b4 = b2; 

    std::cout << "\n--- Exiting Main (Destructors will fire) ---\n";
    system("pause");
    return 0;
}