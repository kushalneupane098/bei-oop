#include <iostream>
using namespace std;

class Matrix2x2 {
    int data[2][2];

public:
    Matrix2x2() {
        data[0][0] = data[0][1] = data[1][0] = data[1][1] = 0;
    }

    Matrix2x2(int a, int b, int c, int d) {
        data[0][0] = a;
        data[0][1] = b;
        data[1][0] = c;
        data[1][1] = d;
    }

    Matrix2x2 operator+(const Matrix2x2& m) {
        return Matrix2x2(
            data[0][0] + m.data[0][0],
            data[0][1] + m.data[0][1],
            data[1][0] + m.data[1][0],
            data[1][1] + m.data[1][1]
        );
    }

    Matrix2x2 operator*(const Matrix2x2& m) {
        return Matrix2x2(
            data[0][0]*m.data[0][0] + data[0][1]*m.data[1][0],
            data[0][0]*m.data[0][1] + data[0][1]*m.data[1][1],
            data[1][0]*m.data[0][0] + data[1][1]*m.data[1][0],
            data[1][0]*m.data[0][1] + data[1][1]*m.data[1][1]
        );
    }

    Matrix2x2 operator-() {
        return Matrix2x2(
            -data[0][0], -data[0][1],
            -data[1][0], -data[1][1]
        );
    }

    friend bool operator==(const Matrix2x2& a, const Matrix2x2& b);

    friend ostream& operator<<(ostream& out, const Matrix2x2& m);
    friend istream& operator>>(istream& in, Matrix2x2& m);
};

bool operator==(const Matrix2x2& a, const Matrix2x2& b) {
    return a.data[0][0] == b.data[0][0] &&
           a.data[0][1] == b.data[0][1] &&
           a.data[1][0] == b.data[1][0] &&
           a.data[1][1] == b.data[1][1];
}

ostream& operator<<(ostream& out, const Matrix2x2& m) {
    out << m.data[0][0] << " " << m.data[0][1] << endl;
    out << m.data[1][0] << " " << m.data[1][1] << endl;
    return out;
}

istream& operator>>(istream& in, Matrix2x2& m) {
    in >> m.data[0][0] >> m.data[0][1]
       >> m.data[1][0] >> m.data[1][1];
    return in;
}

int main() {
    Matrix2x2 A, B;

    cout << "Enter 4 elements for Matrix A: ";
    cin >> A;

    cout << "Enter 4 elements for Matrix B: ";
    cin >> B;

    Matrix2x2 sum = A + B;
    Matrix2x2 product = A * B;
    Matrix2x2 neg = -A;

    cout << "\nMatrix A:\n" << A;
    cout << "\nMatrix B:\n" << B;

    cout << "\nA + B:\n" << sum;
    cout << "\nA * B:\n" << product;
    cout << "\n-A:\n" << neg;

    if (A == B)
        cout << "\nMatrices are equal\n";
    else
        cout << "\nMatrices are not equal\n";

    return 0;
}
