#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

template <class T>
class Stack
{
    vector<T> s;
    int maxSize;

public:
    Stack(int size=3)
    {
        maxSize=size;
    }

    void push(T value)
    {
        if(s.size()>=maxSize)
            throw runtime_error("Stack Overflow");

        s.push_back(value);
    }

    T pop()
    {
        if(s.empty())
            throw runtime_error("Stack Underflow");

        T x=s.back();
        s.pop_back();
        return x;
    }

    void display()
    {
        for(int i=s.size()-1;i>=0;i--)
            cout<<s[i]<<" ";
        cout<<endl;
    }
};

int main()
{
    Stack<int> s1(3);
    Stack<string> s2(3);

    try
    {
        s1.push(10);
        s1.push(20);
        s1.push(30);
        s1.display();
        s1.push(40);
    }
    catch(exception &e)
    {
        cout<<e.what()<<endl;
    }

    try
    {
        s2.push("Apple");
        s2.push("Banana");
        s2.push("Cherry");
        s2.display();

        cout<<s2.pop()<<endl;
        cout<<s2.pop()<<endl;
        cout<<s2.pop()<<endl;
        cout<<s2.pop()<<endl;
    }
    catch(exception &e)
    {
        cout<<e.what()<<endl;
    }

    return 0;
}