#include <iostream>
#include <string>

class BankAccount {
private:
    int accountNumber;
    std::string holderName;
    float balance;

public:
    BankAccount() {
        accountNumber = 0;
        holderName = "Unknown";
        balance = 0.0f;
        std::cout << "Default Constructor: Empty account created.\n";
    }

    BankAccount(int accNum, std::string name, float bal) {
        accountNumber = accNum;
        holderName = name;
        balance = bal;
        std::cout << "Parameterized Constructor: Account for " << holderName << " created.\n";
    }

    ~BankAccount() {
        std::cout << "Destructor: Account " << accountNumber << " closed/destroyed.\n";
    }

    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited $" << amount << ". New Balance: $" << balance << "\n";
        }
    }

    void withdraw(float amount) {
        if (amount > balance) {
            std::cout << "Insufficient balance! Withdrawal failed.\n";
        } else if (amount <= 0) {
            std::cout << "Invalid withdrawal amount.\n";
        } else {
            balance -= amount;
            std::cout << "Withdrew $" << amount << ". Remaining Balance: $" << balance << "\n";
        }
    }

    void display() const {
        std::cout << "Acc No: " << accountNumber << " | Holder: " << holderName << " | Balance: $" << balance << "\n";
    }
};

int main() {
    std::cout << "--- Testing Default Constructor ---\n";
    BankAccount acc1;
    acc1.display();
    
    std::cout << "\n--- Testing Parameterized Constructor ---\n";
    BankAccount acc2(101, "Alice Smith", 500.0f);
    acc2.display();

    std::cout << "\n--- Transactions ---\n";
    acc2.deposit(150.50f);
    acc2.withdraw(200.0f);
    acc2.withdraw(1000.0f); 

    std::cout << "\n--- Exiting Scope ---\n";
    system("pause");
    return 0;
}