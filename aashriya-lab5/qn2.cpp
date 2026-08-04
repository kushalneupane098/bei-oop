#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    Distance(int f = 0, float i = 0)
    {
        feet = f;
        inches = i;
    }

    Distance operator-()
    {
        return Distance(-feet, -inches);
    }

    Distance operator++()
    {
        inches++;

        if (inches >= 12)
        {
            feet++;
            inches -= 12;
        }

        return *this;
    }

    Distance operator++(int)
    {
        Distance temp = *this;

        inches++;

        if (inches >= 12)
        {
            feet++;
            inches -= 12;
        }

        return temp;
    }

    friend Distance operator*(Distance d, int n);
    friend Distance operator*(int n, Distance d);

    void display()
    {
        cout << feet << " ft " << inches << " in";
    }
};

Distance operator*(Distance d, int n)
{
    float total = (d.feet * 12 + d.inches) * n;

    int f = total / 12;
    float i = total - f * 12;

    return Distance(f, i);
}

Distance operator*(int n, Distance d)
{
    return d * n;
}

int main()
{
    Distance d1(5, 10);

    cout << "Original: ";
    d1.display();

    cout << "\nNegated: ";
    (-d1).display();

    cout << "\nPrefix ++ : ";
    (++d1).display();

    cout << "\nPostfix ++ : ";
    (d1++).display();

    cout << "\nAfter Postfix: ";
    d1.display();

    cout << "\nDistance * 2 : ";
    (d1 * 2).display();

    cout << "\n3 * Distance : ";
    (3 * d1).display();

    return 0;
}