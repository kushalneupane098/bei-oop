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

    friend ostream& operator<<(ostream& out, Distance d);
};

Distance operator*(Distance d, int n)
{
    float total = (d.feet * 12 + d.inches) * n;

    Distance result;
    result.feet = total / 12;
    result.inches = (int)total % 12;

    return result;
}

Distance operator*(int n, Distance d)
{
    return d * n;
}

ostream& operator<<(ostream& out, Distance d)
{
    out << d.feet << " ft " << d.inches << " in";
    return out;
}

int main()
{
    Distance d1(5, 10);

    cout << "Original Distance: " << d1 << endl;

    cout << "Negated Distance: " << -d1 << endl;

    cout << "After Prefix ++ : " << ++d1 << endl;

    cout << "Postfix ++ : " << d1++ << endl;

    cout << "After Postfix : " << d1 << endl;

    cout << "Distance * 3 = " << d1 * 3 << endl;

    cout << "3 * Distance = " << 3 * d1 << endl;

    return 0;
}