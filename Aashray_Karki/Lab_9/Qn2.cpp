/*
Question 2:
Define a class template Stack that can hold elements of any data type.
Include push(), pop(), and display(). Create one Stack of integers and one Stack
of strings. Use try-catch to handle stack overflow and underflow.
*/

#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack {
private:
    T arr[3];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(T value) {
        if (top == 2)
            throw "Stack Overflow";

        top++;
        arr[top] = value;
    }

    T pop() {
        if (top == -1)
            throw "Stack Underflow";

        T value = arr[top];
        top--;
        return value;
    }

    void display() const {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    try {
        Stack<int> s1;

        s1.push(10);
        s1.push(20);
        s1.push(30);

        cout << "Integer Stack:" << endl;
        s1.display();

        cout << "Popped: " << s1.pop() << endl;
    }
    catch (const char *msg) {
        cout << "Exception: " << msg << endl;
    }

    try {
        Stack<string> s2;

        s2.push("Apple");
        s2.push("Banana");
        s2.push("Mango");

        cout << "\nString Stack:" << endl;
        s2.display();

        s2.pop();
        s2.pop();
        s2.pop();

        // This causes underflow
        s2.pop();
    }
    catch (const char *msg) {
        cout << "Exception: " << msg << endl;
    }

    return 0;
}