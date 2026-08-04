#include <iostream>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string holderName;
    float balance;

public:
    BankAccount()
    {
        accountNumber = 0;
        holderName = "Unknown";
        balance = 0;
        cout << "Default Constructor Called" << endl;
    }

    BankAccount(int acc, string name, float bal)
    {
        accountNumber = acc;
        holderName = name;
        balance = bal;
        cout << "Parameterized Constructor Called" << endl;
    }

    void deposit(float amount)
    {
        balance += amount;
    }

    void withdraw(float amount)
    {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient Balance" << endl;
    }

    void display()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: " << balance << endl;
    }

    ~BankAccount()
    {
        cout << "Destructor Called" << endl;
    }
};

int main()
{
    BankAccount a1;
    BankAccount a2(101, "John", 5000);

    a2.deposit(1000);
    a2.withdraw(2000);

    a2.display();

    return 0;
}