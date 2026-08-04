#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 5;

class StackOverflowException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Stack Overflow Error: Stack is full!";
    }
};

class StackUnderflowException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Stack Underflow Error: Stack is empty!";
    }
};

template <typename T>
class Stack
{
private:
    T arr[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    void push(T value)
    {
        if (top >= MAX_SIZE - 1)
        {
            throw StackOverflowException();
        }
        arr[++top] = value;
    }

    void pop()
    {
        if (top == -1)
        {
            throw StackUnderflowException();
        }
        top--;
    }

    void display() const
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
            return;
        }
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    try
    {
        Stack<int> intStack;
        intStack.push(10);
        intStack.push(20);
        intStack.push(30);
        intStack.display();
        intStack.pop();
        intStack.display();

        intStack.push(40);
        intStack.push(50);
        intStack.push(60);
        intStack.push(70);
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    try
    {
        Stack<string> stringStack;
        stringStack.push("C++");
        stringStack.push("Java");
        stringStack.push("Python");
        stringStack.display();

        stringStack.pop();
        stringStack.pop();
        stringStack.pop();
        stringStack.pop();
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}