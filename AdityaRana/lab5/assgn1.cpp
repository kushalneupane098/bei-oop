#include <iostream>
using namespace std;

class Matrix {
private:
    int a[2][2];

public:
    Matrix() {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                a[i][j]=0;
    }

    friend istream& operator>>(istream &in, Matrix &m) {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                in >> m.a[i][j];
        return in;
    }

    friend ostream& operator<<(ostream &out, Matrix m) {
        for(int i=0;i<2;i++) {
            for(int j=0;j<2;j++)
                out << m.a[i][j] << " ";
            out << endl;
        }
        return out;
    }

    Matrix operator+(Matrix m) {
        Matrix r;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                r.a[i][j] = a[i][j] + m.a[i][j];
        return r;
    }

    Matrix operator*(Matrix m) {
        Matrix r;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    r.a[i][j] += a[i][k] * m.a[k][j];
        return r;
    }

    Matrix operator-() {
        Matrix r;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                r.a[i][j] = -a[i][j];
        return r;
    }

    friend bool operator==(Matrix a, Matrix b) {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                if(a.a[i][j] != b.a[i][j]) return false;
        return true;
    }
};

int main() {
    Matrix m1, m2;

    cout << "Enter matrix 1:\n";
    cin >> m1;

    cout << "Enter matrix 2:\n";
    cin >> m2;

    cout << "Addition:\n" << (m1 + m2);
    cout << "Multiplication:\n" << (m1 * m2);
    cout << "Negation:\n" << -m1;

    cout << (m1 == m2 ? "Equal" : "Not Equal");
}