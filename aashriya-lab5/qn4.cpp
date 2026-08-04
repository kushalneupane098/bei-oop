#include <iostream>
using namespace std;

class Matrix2x2
{
private:
    int data[2][2];

public:
    Matrix2x2 operator+(Matrix2x2 m)
    {
        Matrix2x2 r;

        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                r.data[i][j]=data[i][j]+m.data[i][j];

        return r;
    }

    Matrix2x2 operator*(Matrix2x2 m)
    {
        Matrix2x2 r;

        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
            {
                r.data[i][j]=0;

                for(int k=0;k<2;k++)
                    r.data[i][j]+=data[i][k]*m.data[k][j];
            }

        return r;
    }

    Matrix2x2 operator-()
    {
        Matrix2x2 r;

        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                r.data[i][j]=-data[i][j];

        return r;
    }

    friend bool operator==(Matrix2x2 a, Matrix2x2 b);

    friend ostream &operator<<(ostream &out, Matrix2x2 m);
    friend istream &operator>>(istream &in, Matrix2x2 &m);
};

bool operator==(Matrix2x2 a, Matrix2x2 b)
{
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            if(a.data[i][j]!=b.data[i][j])
                return false;

    return true;
}

ostream &operator<<(ostream &out, Matrix2x2 m)
{
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
            out << m.data[i][j] << " ";
        out << endl;
    }
    return out;
}

istream &operator>>(istream &in, Matrix2x2 &m)
{
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            in >> m.data[i][j];

    return in;
}

int main()
{
    Matrix2x2 a,b;

    cin >> a >> b;

    cout << a+b;
    cout << a*b;
    cout << -a;

    return 0;
}