#include<iostream>
#include<string>       
using namespace std;

class ATM {
private:
    string ownerName;
    float balance;      

public:
    static int totalTransactions;
    static float totalMoneyMoved;

    ATM(string name, float initialBalance) {
        ownerName = name;
        balance = initialBalance;
    }

    void deposit(float amount) {
        balance += amount;
        totalTransactions++;
        totalMoneyMoved += amount;
    }

    void withdraw(float amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
            return;
        }
        balance -= amount;
        totalTransactions++;
        totalMoneyMoved += amount;
    }

    static void showStats() {
        cout << "\n--- ATM Stats ---" << endl;
        cout << "Total Transactions: " << totalTransactions << endl;
        cout << "Total Money Moved:  $" << totalMoneyMoved << endl;
    }
};

int ATM::totalTransactions = 0;
float ATM::totalMoneyMoved = 0.0f;

int main() {
    ATM acc1("Alice", 1000.0f);
    ATM acc2("Bob", 500.0f);

    acc1.deposit(200.0f);
    acc1.withdraw(150.0f);
    acc2.deposit(300.0f);
    acc2.withdraw(700.0f);  

    ATM::showStats();
}