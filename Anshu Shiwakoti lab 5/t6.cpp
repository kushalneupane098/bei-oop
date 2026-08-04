#include <iostream>
#include <cmath>
using namespace std;

class Vector3D
{
private:
    float x, y, z;

public:
    Vector3D(float v = 0)
    {
        x = y = z = v;
    }

    Vector3D(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }

    Vector3D operator+(const Vector3D &v)
    {
        return Vector3D(x + v.x, y + v.y, z + v.z);
    }

    Vector3D operator-(const Vector3D &v)
    {
        return Vector3D(x - v.x, y - v.y, z - v.z);
    }

    Vector3D operator-()
    {
        return Vector3D(-x, -y, -z);
    }

    operator float() const
    {
        return sqrt(x * x + y * y + z * z);
    }

    friend float operator*(const Vector3D &a, const Vector3D &b);

    friend Vector3D operator*(const Vector3D &v, float s);

    friend Vector3D operator*(float s, const Vector3D &v);

    friend ostream &operator<<(ostream &out, const Vector3D &v);

    friend istream &operator>>(istream &in, Vector3D &v);
};

float operator*(const Vector3D &a, const Vector3D &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3D operator*(const Vector3D &v, float s)
{
    return Vector3D(v.x * s, v.y * s, v.z * s);
}

Vector3D operator*(float s, const Vector3D &v)
{
    return Vector3D(v.x * s, v.y * s, v.z * s);
}

ostream &operator<<(ostream &out, const Vector3D &v)
{
    out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return out;
}

istream &operator>>(istream &in, Vector3D &v)
{
    cout << "Enter x y z: ";
    in >> v.x >> v.y >> v.z;
    return in;
}

int main()
{
    Vector3D v1, v2;

    cin >> v1;
    cin >> v2;

    cout << "Vector 1: " << v1 << endl;
    cout << "Vector 2: " << v2 << endl;

    cout << "Addition: " << v1 + v2 << endl;
    cout << "Subtraction: " << v1 - v2 << endl;
    cout << "Unary Minus: " << -v1 << endl;

    cout << "Dot Product: " << v1 * v2 << endl;

    cout << "Vector * Scalar: " << v1 * 2.0f << endl;
    cout << "Scalar * Vector: " << 3.0f * v1 << endl;

    float mag = v1;
    cout << "Magnitude of Vector 1: " << mag << endl;

    Vector3D v3 = 5.0f;
    cout << "Vector from Float: " << v3 << endl;

    return 0;
}