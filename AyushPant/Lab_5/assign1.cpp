#include<iostream>
using namespace std;

class Matrix2x2 {
    int data[2][2];
public:
    Matrix2x2() { for(int i=0;i<2;i++) for(int j=0;j<2;j++) data[i][j]=0; }
    Matrix2x2 operator+(const Matrix2x2& m) {
        Matrix2x2 r;
        for(int i=0;i<2;i++) for(int j=0;j<2;j++) r.data[i][j]=data[i][j]+m.data[i][j];
        return r;
    }
    Matrix2x2 operator*(const Matrix2x2& m) {
        Matrix2x2 r;
        for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++) r.data[i][j]+=data[i][k]*m.data[k][j];
        return r;
    }
    Matrix2x2 operator-() {
        Matrix2x2 r;
        for(int i=0;i<2;i++) for(int j=0;j<2;j++) r.data[i][j]=-data[i][j];
        return r;
    }
    friend bool operator==(const Matrix2x2& a, const Matrix2x2& b) {
        for(int i=0;i<2;i++) for(int j=0;j<2;j++) if(a.data[i][j]!=b.data[i][j]) return false;
        return true;
    }
    friend ostream& operator<<(ostream& os, const Matrix2x2& m) {
        os << m.data[0][0] << " " << m.data[0][1] << "\n" << m.data[1][0] << " " << m.data[1][1];
        return os;
    }
    friend istream& operator>>(istream& is, Matrix2x2& m) {
        for(int i=0;i<2;i++) for(int j=0;j<2;j++) is >> m.data[i][j];
        return is;
    }
};

int main() {
    Matrix2x2 a, b;
    cout << "Enter 4 elements for A: "; cin >> a;
    cout << "Enter 4 elements for B: "; cin >> b;
    cout << "A:\n" << a << "\nB:\n" << b << endl;
    cout << "A+B:\n" << a+b << endl;
    cout << "A*B:\n" << a*b << endl;
    cout << "-A:\n" << -a << endl;
    cout << "A==B: " << (a==b ? "true" : "false") << endl;
    return 0;
}
