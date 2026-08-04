#include <iostream>
using namespace std;

class Matrix2x2
{
    int data[2][2];

public:
    friend istream& operator>>(istream &in, Matrix2x2 &m)
    {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                in>>m.data[i][j];
        return in;
    }

    friend ostream& operator<<(ostream &out,const Matrix2x2 &m)
    {
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
                out<<m.data[i][j]<<" ";
            out<<endl;
        }
        return out;
    }

    Matrix2x2 operator+(Matrix2x2 m)
    {
        Matrix2x2 t;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                t.data[i][j]=data[i][j]+m.data[i][j];
        return t;
    }

    Matrix2x2 operator*(Matrix2x2 m)
    {
        Matrix2x2 t;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                t.data[i][j]=0;
                for(int k=0;k<2;k++)
                    t.data[i][j]+=data[i][k]*m.data[k][j];
            }
        }
        return t;
    }

    Matrix2x2 operator-()
    {
        Matrix2x2 t;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                t.data[i][j]=-data[i][j];
        return t;
    }

    friend bool operator==(Matrix2x2 a, Matrix2x2 b)
    {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                if(a.data[i][j]!=b.data[i][j])
                    return false;
        return true;
    }
};

int main()
{
    Matrix2x2 a,b,c;

    cout<<"Enter matrix A:\n";
    cin>>a;

    cout<<"Enter matrix B:\n";
    cin>>b;

    c=a+b;
    cout<<"\nA+B:\n"<<c;

    c=a*b;
    cout<<"\nA*B:\n"<<c;

    cout<<"\n-A:\n"<<-a;

    if(a==b)
        cout<<"\nMatrices are equal";
    else
        cout<<"\nMatrices are not equal";

    return 0;
}