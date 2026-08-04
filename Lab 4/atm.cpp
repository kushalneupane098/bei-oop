#include<iostream>
using namespace std;

class ATM
{
private:
    string ownerName;
    float balance;

    static int totalTransactions;
    static float totalMoneyMoved;

public:
    ATM(string n, float b)
    {
        ownerName = n;
        balance = b;
    }

    void deposit(float amt)
    {
        balance = balance + amt;
        totalTransactions++;
        totalMoneyMoved += amt;
    }

    void withdraw(float amt)
    {
        if(amt <= balance)
        {
            balance = balance - amt;
            totalTransactions++;
            totalMoneyMoved += amt;
        }
        else
            cout<<"Insufficient Balance"<<endl;
    }

    void display()
    {
        cout<<"Name : "<<ownerName<<endl;
        cout<<"Balance : "<<balance<<endl;
    }

    static void showStats()
    {
        cout<<"Total Transactions : "<<totalTransactions<<endl;
        cout<<"Total Money Moved : "<<totalMoneyMoved<<endl;
    }
};

int ATM::totalTransactions = 0;
float ATM::totalMoneyMoved = 0;

int main()
{
    ATM a1("Ram",5000);
    ATM a2("Hari",7000);

    a1.deposit(1000);
    a2.withdraw(500);

    a1.display();
    a2.display();

    ATM::showStats();

    return 0;
}