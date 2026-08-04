#include <iostream>
using namespace std;

class T {
private:
  float c;

public:
  T(float x) { c = x; }

  void set(float x) { c = x; }

  float f() const { return (c * 9.0f / 5.0f) + 32.0f; }

  float k() const { return c + 273.15f; }

  friend bool eq(T a, T b);
};

bool eq(T a, T b) { return a.c == b.c; }

int main() {
  T a(25.0f);
  T b(100.0f);

  cout << "A F: " << a.f() << endl;
  cout << "A K: " << a.k() << endl;
  cout << "B F: " << b.f() << endl;

  if (eq(a, b))
    cout << "A = B" << endl;
  else
    cout << "A != B" << endl;

  cout << "\nSet B = A\n";
  b.set(25.0f);

  if (eq(a, b))
    cout << "A = B" << endl;
  else
    cout << "A != B" << endl;

  return 0;
}
