#include <iostream>
#include <string>
using namespace std;

class ATM {
private:
    string ownerName;
    float balance;
    static int totalTransactions;
    static float totalMoneyMoved;

public:
    ATM(string name, float initialBalance) {
        ownerName = name;
        balance = initialBalance;
    }

    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            totalTransactions++;
            totalMoneyMoved += amount;
            cout << amount << " deposited successfully to " << ownerName << "'s account." << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(float amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            totalTransactions++;
            totalMoneyMoved += amount;
            cout << amount << " withdrawn successfully from " << ownerName << "'s account." << endl;
        } else {
            cout << "Invalid amount or insufficient balance for " << ownerName << "." << endl;
        }
    }

    static void showStats() {
        cout << "\nCombined ATM Network Statistics" << endl;
        cout << "Total Transactions Executed: " << totalTransactions << endl;
        cout << "Total Money Moved: Rs. " << totalMoneyMoved << endl;
    }
};

int ATM::totalTransactions = 0;
float ATM::totalMoneyMoved = 0.0;

int main() {
    ATM account1("Bardan", 50000.0);
    ATM account2("Kushal", 30000.0);

    account1.deposit(10000);
    account2.withdraw(5000);
    account1.withdraw(2000);

    ATM::showStats();

    return 0;
}