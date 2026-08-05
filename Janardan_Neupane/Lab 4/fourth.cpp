#include <iostream>
using namespace std;

class Maths;

class Physics {
private:
	int marks;

public:
	void setMarks(int m) { marks = m; }
	friend int totalMarks(const Physics& p, const Maths& m);
	friend bool isDistinction(const Physics& p, const Maths& m);
};

class Maths {
private:
	int marks;

public:
	void setMarks(int m) { marks = m; }
	friend int totalMarks(const Physics& p, const Maths& m);
	friend bool isDistinction(const Physics& p, const Maths& m);
};

int totalMarks(const Physics& p, const Maths& m) {
	return p.marks + m.marks;
}

bool isDistinction(const Physics& p, const Maths& m) {
	return totalMarks(p, m) >= 160;
}

int main() {
	Physics p;
	Maths m;
	int physicsMark, mathsMark;

	cout << "Enter Physics marks: ";
	cin >> physicsMark;
	cout << "Enter Maths marks: ";
	cin >> mathsMark;

	p.setMarks(physicsMark);
	m.setMarks(mathsMark);

	int total = totalMarks(p, m);
	cout << "Total marks: " << total << endl;
	cout << (isDistinction(p, m) ? "Distinction achieved" : "Distinction not achieved") << endl;

	return 0;
}

