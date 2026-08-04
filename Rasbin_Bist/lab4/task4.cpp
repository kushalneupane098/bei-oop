

#include <iostream>
using namespace std;

class M;

class P {
private:
  int m;

public:
  P(int x) { m = x; }

  friend int t(P p, M q);
  friend bool d(P p, M q);
};

class M {
private:
  int m;

public:
  M(int x) { m = x; }

  friend int t(P p, M q);
  friend bool d(P p, M q);
};

int t(P p, M q) { return p.m + q.m; }

bool d(P p, M q) { return t(p, q) >= 160; }

int main() {
  int p, m;

  cout << "Enter Physics marks: ";
  cin >> p;

  cout << "Enter Maths marks: ";
  cin >> m;

  P a(p);
  M b(m);

  int s = t(a, b);

  cout << "\nTotal Marks: " << s << " / 200" << endl;

  if (d(a, b))
    cout << "Result: Distinction achieved!" << endl;
  else
    cout << "Result: No distinction." << endl;

  return 0;
}