#include <iostream>
using namespace std;

class Matrix2x2
{
private:
    int data[2][2];

public:
    
    friend istream &operator>>(istream &in, Matrix2x2 &m);

    friend ostream &operator<<(ostream &out, const Matrix2x2 &m);

    Matrix2x2 operator+(const Matrix2x2 &m)
    {
        Matrix2x2 temp;

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                temp.data[i][j] = data[i][j] + m.data[i][j];

        return temp;
    }

    Matrix2x2 operator*(const Matrix2x2 &m)
    {
        Matrix2x2 temp;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                temp.data[i][j] = 0;

                for (int k = 0; k < 2; k++)
                    temp.data[i][j] += data[i][k] * m.data[k][j];
            }
        }

        return temp;
    }
    Matrix2x2 operator-()
    {
        Matrix2x2 temp;

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                temp.data[i][j] = -data[i][j];

        return temp;
    }

    friend bool operator==(const Matrix2x2 &a, const Matrix2x2 &b);
};

istream &operator>>(istream &in, Matrix2x2 &m)
{
    cout << "Enter 4 elements:\n";

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            in >> m.data[i][j];

    return in;
}

ostream &operator<<(ostream &out, const Matrix2x2 &m)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            out << m.data[i][j] << " ";
        out << endl;
    }

    return out;
}

bool operator==(const Matrix2x2 &a, const Matrix2x2 &b)
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (a.data[i][j] != b.data[i][j])
                return false;

    return true;
}

int main()
{
    Matrix2x2 m1, m2, sum, product, neg;

    cout << "Matrix 1\n";
    cin >> m1;

    cout << "\nMatrix 2\n";
    cin >> m2;

    sum = m1 + m2;
    product = m1 * m2;
    neg = -m1;

    cout << "\nMatrix 1\n" << m1;
    cout << "\nMatrix 2\n" << m2;

    cout << "\nAddition\n" << sum;

    cout << "\nMultiplication\n" << product;

    cout << "\nNegative of Matrix 1\n" << neg;

    if (m1 == m2)
        cout << "\nMatrices are Equal\n";
    else
        cout << "\nMatrices are Not Equal\n";

    return 0;
}