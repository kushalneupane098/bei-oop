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
            inches = 0;
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
            inches = 0;
        }

        return temp;
    }

    friend Distance operator*(Distance d, int n);
    friend Distance operator*(int n, Distance d);
    friend ostream &operator<<(ostream &out, const Distance &d);
};

Distance operator*(Distance d, int n)
{
    int total = (d.feet * 12 + d.inches) * n;

    d.feet = total / 12;
    d.inches = total % 12;

    return d;
}

Distance operator*(int n, Distance d)
{
    return d * n;
}

ostream &operator<<(ostream &out, const Distance &d)
{
    out << d.feet << " feet " << d.inches << " inches";
    return out;
}

int main()
{
    Distance d1(5, 8);

    cout << "Original Distance : " << d1 << endl;

    cout << "Unary - : " << -d1 << endl;

    ++d1;
    cout << "After Prefix ++ : " << d1 << endl;

    d1++;
    cout << "After Postfix ++ : " << d1 << endl;

    Distance d2 = d1 * 2;
    cout << "Distance * 2 = " << d2 << endl;

    Distance d3 = 3 * d1;
    cout << "3 * Distance = " << d3 << endl;

    return 0;
}