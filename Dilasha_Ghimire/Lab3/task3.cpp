#include <iostream>
using namespace std;

class BankAccount {
private:
    int acc;
    string name;
    float bal;

public:
    BankAccount() {
        acc = 0;
        name = "Unknown";
        bal = 0;
        cout << "Default account created\n";
    }

    BankAccount(int a, string n, float b) {
        acc = a;
        name = n;
        bal = b;
        cout << "Account created for " << name << "\n";
    }

    ~BankAccount() {
        cout << "Account " << acc << " closed\n";
    }

    void deposit(float x) {
        if (x > 0) {
            bal += x;
            cout << "Deposited " << x << "\n";
        }
    }

    void withdraw(float x) {
        if (x > bal) {
            cout << "Not enough balance\n";
        } else if (x > 0) {
            bal -= x;
            cout << "Withdraw " << x << "\n";
        }
    }

    void display() {
        cout << acc << " " << name << " " << bal << "\n";
    }
};

int main() {
    BankAccount a1;
    BankAccount a2(101, "shri", 500.50);

    cout << "\n";
    a2.display();

    a2.deposit(150);
    a2.withdraw(50);

    a2.display();

    return 0;
}