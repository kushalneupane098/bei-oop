#include <iostream>
#include <cmath>

using namespace std;

class Vector3D
{
private:
    float x, y, z;

public:
    Vector3D()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Vector3D(float x1, float y1, float z1)
    {
        x = x1;
        y = y1;
        z = z1;
    }

    Vector3D(float val)
    {
        x = val;
        y = val;
        z = val;
    }

    Vector3D operator+(Vector3D v)
    {
        return Vector3D(x + v.x, y + v.y, z + v.z);
    }

    Vector3D operator-(Vector3D v)
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

    friend float operator*(Vector3D v1, Vector3D v2)
    {
        return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
    }

    friend Vector3D operator*(Vector3D v, float s)
    {
        return Vector3D(v.x * s, v.y * s, v.z * s);
    }

    friend Vector3D operator*(float s, Vector3D v)
    {
        return Vector3D(v.x * s, v.y * s, v.z * s);
    }

    friend ostream &operator<<(ostream &os, Vector3D v)
    {
        os << v.x << " " << v.y << " " << v.z;
        return os;
    }

    friend istream &operator>>(istream &is, Vector3D &v)
    {
        is >> v.x >> v.y >> v.z;
        return is;
    }
};

int main()
{
    Vector3D v1;
    Vector3D v2(1, 2, 3);

    cout << "Enter x, y, z for v1: ";
    cin >> v1;

    cout << "\nAdd: " << v1 + v2 << "\n";
    cout << "Sub: " << v1 - v2 << "\n";
    cout << "Neg: " << -v1 << "\n";

    cout << "\nDot product: " << v1 * v2 << "\n";
    cout << "v1 * 2: " << v1 * 2.0f << "\n";
    cout << "2 * v1: " << 2.0f * v1 << "\n";

    float mag = v1;
    cout << "\nMagnitude: " << mag << "\n";
    cout << "From float (4.5): " << Vector3D(4.5f) << "\n";

    return 0;
}