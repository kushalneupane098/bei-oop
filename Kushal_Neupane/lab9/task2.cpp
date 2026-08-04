#include <iostream>
#include <string>
using namespace std;

const int MAX = 5;

template <typename T>
class Stack {
    T arr[MAX];
    int top;
public:
    Stack() : top(-1) {}

    void push(T val) {
        if (top >= MAX - 1) throw overflow_error("Stack Overflow!");
        arr[++top] = val;
    }

    T pop() {
        if (top < 0) throw underflow_error("Stack Underflow!");
        return arr[top--];
    }

    void display() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    try {
        Stack<int> intStack;
        intStack.push(10);
        intStack.push(20);
        intStack.push(30);
        intStack.display();

        Stack<string> strStack;
        strStack.push("Hello");
        strStack.push("World");
        strStack.push("Stack");
        strStack.display();

        cout << "Popped from intStack: " << intStack.pop() << endl;
        intStack.display();

    } catch (const exception &e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
