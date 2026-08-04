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
        cout << "Default Constructor Called\n";
    }
    BankAccount(int acc, string name, float bal) {
        accountNumber = acc;
        holderName = name;
        balance = bal;
        cout << "Parameterized Constructor Called\n";
    }
    void deposit(float amount) {
        balance += amount;
    }
    void withdraw(float amount) {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient Balance\n";
    }
    void display() {
        cout << "\nAccount No: " << accountNumber << endl;
        cout << "Name: " << holderName << endl;
        cout << "Balance: " << balance << endl;
    }
    ~BankAccount() {
        cout << "Account Closed\n";
    }
};
int main() {
    BankAccount a1;                      
    BankAccount a2(101, "Aditya", 5000); 

    a2.deposit(1000);
    a2.withdraw(2000);

    a2.display();

    return 0;
}