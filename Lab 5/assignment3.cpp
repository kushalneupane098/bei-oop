#include <iostream>
#include <cmath>
using namespace std;

class Vector3D {
    float x, y, z;

public:
    Vector3D(float val = 0) {
        x = y = z = val;
    }

    Vector3D(float a, float b, float c) {
        x = a;
        y = b;
        z = c;
    }

    Vector3D operator+(const Vector3D& v) const {
        return Vector3D(x + v.x, y + v.y, z + v.z);
    }

    Vector3D operator-(const Vector3D& v) const {
        return Vector3D(x - v.x, y - v.y, z - v.z);
    }

    Vector3D operator-() const {
        return Vector3D(-x, -y, -z);
    }

    operator float() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    friend float operator*(const Vector3D& a, const Vector3D& b);

    friend Vector3D operator*(const Vector3D& v, float s);
    friend Vector3D operator*(float s, const Vector3D& v);

    friend ostream& operator<<(ostream& out, const Vector3D& v);
    friend istream& operator>>(istream& in, Vector3D& v);
};

float operator*(const Vector3D& a, const Vector3D& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3D operator*(const Vector3D& v, float s) {
    return Vector3D(v.x * s, v.y * s, v.z * s);
}

Vector3D operator*(float s, const Vector3D& v) {
    return Vector3D(v.x * s, v.y * s, v.z * s);
}

ostream& operator<<(ostream& out, const Vector3D& v) {
    out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return out;
}

istream& operator>>(istream& in, Vector3D& v) {
    in >> v.x >> v.y >> v.z;
    return in;
}

int main() {
    Vector3D v1, v2;

    cout << "Enter vector v1 (x y z): ";
    cin >> v1;

    cout << "Enter vector v2 (x y z): ";
    cin >> v2;

    Vector3D sum = v1 + v2;
    Vector3D diff = v1 - v2;
    Vector3D neg = -v1;

    float dot = v1 * v2;

    Vector3D s1 = v1 * 2.0;
    Vector3D s2 = 3.0 * v2;

    float mag = (float)v1;

    Vector3D v3 = 5.0;

    cout << "\nv1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;

    cout << "\nv1 + v2 = " << sum << endl;
    cout << "v1 - v2 = " << diff << endl;
    cout << "-v1 = " << neg << endl;

    cout << "\nDot product v1 * v2 = " << dot << endl;

    cout << "\nv1 * 2 = " << s1 << endl;
    cout << "3 * v2 = " << s2 << endl;

    cout << "\nMagnitude of v1 = " << mag << endl;

    cout << "\nVector from single value (5.0): " << v3 << endl;

    return 0;
}