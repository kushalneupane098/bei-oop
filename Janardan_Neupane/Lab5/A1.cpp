#include <iostream>

using namespace std;

class Matrix2x2
{
private:
    int data[2][2];

public:
    Matrix2x2()
    {
        data[0][0] = 0;
        data[0][1] = 0;
        data[1][0] = 0;
        data[1][1] = 0;
    }

    Matrix2x2(int a, int b, int c, int d)
    {
        data[0][0] = a;
        data[0][1] = b;
        data[1][0] = c;
        data[1][1] = d;
    }

    Matrix2x2 operator+(Matrix2x2 m)
    {
        return Matrix2x2(
            data[0][0] + m.data[0][0],
            data[0][1] + m.data[0][1],
            data[1][0] + m.data[1][0],
            data[1][1] + m.data[1][1]);
    }

    Matrix2x2 operator*(Matrix2x2 m)
    {
        return Matrix2x2(
            data[0][0] * m.data[0][0] + data[0][1] * m.data[1][0],
            data[0][0] * m.data[0][1] + data[0][1] * m.data[1][1],
            data[1][0] * m.data[0][0] + data[1][1] * m.data[1][0],
            data[1][0] * m.data[0][1] + data[1][1] * m.data[1][1]);
    }

    Matrix2x2 operator-()
    {
        return Matrix2x2(-data[0][0], -data[0][1], -data[1][0], -data[1][1]);
    }

    friend bool operator==(Matrix2x2 m1, Matrix2x2 m2)
    {
        return (m1.data[0][0] == m2.data[0][0] &&
                m1.data[0][1] == m2.data[0][1] &&
                m1.data[1][0] == m2.data[1][0] &&
                m1.data[1][1] == m2.data[1][1]);
    }

    friend ostream &operator<<(ostream &os, Matrix2x2 m)
    {
        os << m.data[0][0] << " " << m.data[0][1] << "\n"
           << m.data[1][0] << " " << m.data[1][1];
        return os;
    }

    friend istream &operator>>(istream &is, Matrix2x2 &m)
    {
        is >> m.data[0][0] >> m.data[0][1] >> m.data[1][0] >> m.data[1][1];
        return is;
    }
};

int main()
{
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2;

    cout << "Enter 4 numbers for matrix: ";
    cin >> m2;

    cout << "\nMatrix m1:\n"
         << m1 << "\n";
    cout << "\nMatrix m2:\n"
         << m2 << "\n";

    cout << "\nm1 + m2:\n"
         << (m1 + m2) << "\n";
    cout << "\nm1 * m2:\n"
         << (m1 * m2) << "\n";
    cout << "\n-m1:\n"
         << (-m1) << "\n";
    cout << "\nEqual: " << (m1 == m2) << "\n";

    return 0;
}