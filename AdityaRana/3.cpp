
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
        balance = 0;
        cout << "Default constructor called\n";
    }

       BankAccount(int acc, string name, float bal) {
        accountNumber = acc;
        holderName = name;
        balance = bal;
        cout << "Parameterised constructor called\n";
    }

       ~BankAccount() {
        cout << "Destructor called for account: " << accountNumber << "\n";
    }

    void deposit(float amount) {
        balance = balance + amount;
        cout << "Deposited: " << amount << "\n";
    }

    void withdraw(float amount) {
        if (amount > balance)
            cout << "Insufficient funds!\n";
        else {
            balance = balance - amount;
            cout << "Withdrawn: " << amount << "\n";
        }
    }

    void display() {
        cout << "Account No : " << accountNumber << "\n";
        cout << "Name       : " << holderName << "\n";
        cout << "Balance    : " << balance << "\n";
        cout << "------------------------\n";
    }
};

int main() {
    BankAccount a1;                          
    BankAccount a2(101, "Alice", 5000.0);    

    a1.display();

    a2.deposit(1500);
    a2.withdraw(200);
    a2.withdraw(9999);  
    a2.display();

    return 0;
}