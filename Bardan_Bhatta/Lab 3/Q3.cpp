#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string holderName;
    float balance;

public:
    BankAccount() {
        accountNumber = 0;
        holderName = "Unknown";
        balance = 0.0;
        cout << "[System]: Default account initialized." << endl;
    }

    BankAccount(int accNum, string name, float initialBalance) {
        accountNumber = accNum;
        holderName = name;
        balance = initialBalance;
        cout << "[System]: Parameterised account initialized for " << holderName << "." << endl;
    }

    ~BankAccount() {
        cout << "[System]: Account " << accountNumber << " closed." << endl;
    }

    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited Rs. " << amount << " successful." << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(float amount) {
        if (amount > balance) {
            cout << "Insufficient balance! Withdrawal failed." << endl;
        } else if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
        } else {
            balance -= amount;
            cout << "Withdrew Rs. " << amount << " successfully." << endl;
        }
    }

    void display() const {
        cout << "Account Number : " << accountNumber << endl;
        cout << "Holder Name    : " << holderName << endl;
        cout << "Current Balance: Rs. " << balance << endl;
    }
};

int main() {
    BankAccount acc1;
    acc1.display();

    BankAccount acc2(101202, "Ram Bahadur", 5000.50);
    acc2.display();

    acc2.deposit(2500.0);
    acc2.withdraw(1200.50);
    acc2.display();

    return 0;
}