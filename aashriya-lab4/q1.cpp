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
   
    ATM(string name, float bal) {
        ownerName = name;
        balance = bal;
    }

  
    void deposit(float amount) {
        balance += amount;
        totalTransactions++;
        totalMoneyMoved += amount;

        cout << ownerName << " deposited Rs. " << amount << endl;
    }

    
    void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
            totalTransactions++;
            totalMoneyMoved += amount;

            cout << ownerName << " withdrew Rs. " << amount << endl;
        } else {
            cout << "Insufficient balance for " << ownerName << endl;
        }
    }

  
    void showBalance() {
        cout << ownerName << "'s Balance: Rs. " << balance << endl;
    }

   
    static void showStats() {
        cout << "\n----- ATM Statistics -----" << endl;
        cout << "Total Transactions: " << totalTransactions << endl;
        cout << "Total Money Moved: Rs. " << totalMoneyMoved << endl;
    }
};

// Definition of static members
int ATM::totalTransactions = 0;
float ATM::totalMoneyMoved = 0.0;

// Main function
int main() {
    ATM atm1("Alice", 5000);
    ATM atm2("Bob", 3000);

    atm1.deposit(1000);
    atm1.withdraw(500);

    atm2.deposit(2000);
    atm2.withdraw(1000);

    cout << endl;
    atm1.showBalance();
    atm2.showBalance();

    ATM::showStats();

    return 0;
}