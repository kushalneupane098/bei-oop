#include <iostream>
#include <string>
using namespace std;

class B {
private:
  string t;
  string a;
  bool v;

public:
  B(string x, string y) {
    t = x;
    a = y;
    v = true;
  }

  string gt() const { return t; }
  string ga() const { return a; }

  void c() {
    if (v) {
      v = false;
      cout << t << " has been checked out." << endl;
    } else {
      cout << t << " is already checked out!" << endl;
    }
  }

  void r() {
    v = true;
    cout << t << " has been returned." << endl;
  }

  void d() const {
    cout << "Title: " << t << ", Author: " << a
         << ", Status: " << (v ? "Available" : "Checked Out") << endl;
  }
};

void p(const B &b) {
  cout << "\n[Book Info]" << endl;
  cout << "Book Title: " << b.gt() << endl;
  cout << "Book Author: " << b.ga() << endl;
  b.d();
}

int main() {
  B b("2001", "George RR Martin");

  cout << "Initial status:" << endl;
  b.d();

  cout << "\nPerforming actions:" << endl;
  b.c();
  b.c();

  p(b);

  cout << "\nReturning the book:" << endl;
  b.r();
  b.d();

  return 0;
}