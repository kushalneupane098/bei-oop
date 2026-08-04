#include <iostream>
using namespace std;

class ATM
{
private:
    string ownerName;
    float balance;

    static int totalTransactions;
    static float totalMoneyMoved;

public:
    ATM(string name, float bal)
    {
        ownerName = name;
        balance = bal;
    }

    void deposit(float amount)
    {
        balance += amount;
        totalTransactions++;
        totalMoneyMoved += amount;
    }

    void withdraw(float amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            totalTransactions++;
            totalMoneyMoved += amount;
        }
        else
            cout << "Insufficient Balance\n";
    }

    void display()
    {
        cout << ownerName << " Balance = " << balance << endl;
    }

    static void showStats()
    {
        cout << "\nTotal Transactions = " << totalTransactions << endl;
        cout << "Total Money Moved = " << totalMoneyMoved << endl;
    }
};

int ATM::totalTransactions = 0;
float ATM::totalMoneyMoved = 0;

int main()
{
    ATM a1("Ram", 5000);
    ATM a2("Shyam", 7000);

    a1.deposit(1000);
    a1.withdraw(500);

    a2.deposit(2000);
    a2.withdraw(1000);

    a1.display();
    a2.display();

    ATM::showStats();

    return 0;
}