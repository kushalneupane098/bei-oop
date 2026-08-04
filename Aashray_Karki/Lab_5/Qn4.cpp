/*
Assignment 1:
Write a program with a class Matrix2x2 having a private 2D integer array
data[2][2]. Overload the binary + operator as a member function for matrix
addition, the binary * operator as a member function for matrix multiplication,
and the unary - operator as a member function that negates all elements.
Overload the == operator as a friend function for element-wise equality.
Overload << to display the matrix in a readable 2-row grid format and >>
to read all four elements. Demonstrate all operators in main using at least
two Matrix2x2 objects.
*/

#include <iostream>
using namespace std;

class Matrix2x2 {
private:
    int data[2][2];

public:
    Matrix2x2() {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                data[i][j] = 0;
    }

    Matrix2x2 operator+(const Matrix2x2& m) const {
        Matrix2x2 result;

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                result.data[i][j] = data[i][j] + m.data[i][j];

        return result;
    }

    Matrix2x2 operator*(const Matrix2x2& m) const {
        Matrix2x2 result;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.data[i][j] = 0;

                for (int k = 0; k < 2; k++)
                    result.data[i][j] += data[i][k] * m.data[k][j];
            }
        }

        return result;
    }

    Matrix2x2 operator-() const {
        Matrix2x2 result;

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                result.data[i][j] = -data[i][j];

        return result;
    }

    friend bool operator==(const Matrix2x2& m1, const Matrix2x2& m2);
    friend istream& operator>>(istream& input, Matrix2x2& m);
    friend ostream& operator<<(ostream& output, const Matrix2x2& m);
};

bool operator==(const Matrix2x2& m1, const Matrix2x2& m2) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (m1.data[i][j] != m2.data[i][j])
                return false;

    return true;
}

istream& operator>>(istream& input, Matrix2x2& m) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            input >> m.data[i][j];

    return input;
}

ostream& operator<<(ostream& output, const Matrix2x2& m) {
    for (int i = 0; i < 2; i++) {
        output << "| ";

        for (int j = 0; j < 2; j++)
            output << m.data[i][j] << " ";

        output << "|" << endl;
    }

    return output;
}

int main() {
    Matrix2x2 m1, m2;

    cout << "Enter four elements of Matrix 1: ";
    cin >> m1;

    cout << "Enter four elements of Matrix 2: ";
    cin >> m2;

    cout << "\nMatrix 1:\n" << m1;
    cout << "\nMatrix 2:\n" << m2;

    cout << "\nMatrix Addition:\n" << m1 + m2;
    cout << "\nMatrix Multiplication:\n" << m1 * m2;
    cout << "\nNegative of Matrix 1:\n" << -m1;

    if (m1 == m2)
        cout << "\nBoth matrices are equal." << endl;
    else
        cout << "\nThe matrices are not equal." << endl;

    return 0;
}