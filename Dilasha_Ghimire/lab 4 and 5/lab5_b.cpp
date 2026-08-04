#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    float inches;

public:
    Distance(int f = 0, float i = 0) {
        feet = f;
        inches = i;
    }

    // Unary -
    Distance operator-() {
        return Distance(-feet, -inches);
    }

    // Prefix ++
    Distance operator++() {
        inches++;

        if (inches >= 12) {
            feet++;
            inches -= 12;
        }

        return *this;
    }

    // Postfix ++
    Distance operator++(int) {
        Distance temp = *this;

        inches++;

        if (inches >= 12) {
            feet++;
            inches -= 12;
        }

        return temp;
    }

    friend Distance operator*(Distance d,int n);

    friend Distance operator*(int n,Distance d);

    void display() {
        cout << feet << " feet "
             << inches << " inches\n";
    }
};

Distance operator*(Distance d, int n) {
    return Distance(d.feet * n, d.inches * n);
}

Distance operator*(int n, Distance d) {
    return Distance(d.feet * n,d.inches * n);
}

int main() {
    Distance d1(5, 10);

    cout << "Original Distance: ";
    d1.display();

    Distance d2 = -d1;
    cout << "After Unary - : ";
    d2.display();

    ++d1;
    cout << "After Prefix ++ : ";
    d1.display();

    d1++;
    cout << "After Postfix ++ : ";
    d1.display();

    Distance d3 = d1 * 2;
    cout << "Distance * 2 : ";
    d3.display();

    Distance d4 = 3 * d1;
    cout << "3 * Distance : ";
    d4.display();

    return 0;
}