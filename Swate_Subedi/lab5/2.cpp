#include <iostream>

using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    Distance() : feet(0), inches(0) {}
    Distance(int f, float i) : feet(f), inches(i) {}

    Distance operator-() const
    {
        return Distance(-feet, -inches);
    }

    Distance &operator++()
    {
        inches++;
        if (inches >= 12.0)
        {
            feet++;
            inches -= 12.0;
        }
        return *this;
    }

    Distance operator++(int)
    {
        Distance temp = *this;
        ++(*this);
        return temp;
    }

    friend Distance operator*(const Distance &d, int scalar)
    {
        float totalInches = (d.feet * 12 + d.inches) * scalar;
        return Distance(static_cast<int>(totalInches) / 12, totalInches - (static_cast<int>(totalInches) / 12) * 12);
    }

    friend Distance operator*(int scalar, const Distance &d)
    {
        return d * scalar;
    }

    friend ostream &operator<<(ostream &os, const Distance &d)
    {
        os << d.feet << " ft " << d.inches << " in";
        return os;
    }
};

int main()
{
    Distance d1(5, 11), d2;
    cout << "d1: " << d1 << "\n";
    cout << "-d1: " << -d1 << "\n";
    cout << "++d1: " << ++d1 << "\n";
    d2 = d1++;
    cout << "d2 (after d1++): " << d2 << " | d1 now: " << d1 << "\n";
    cout << "d1 * 2: " << d1 * 2 << "\n";
    return 0;
}