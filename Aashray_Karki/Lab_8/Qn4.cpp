/*
Question 4:
Write a program for transaction processing that writes and reads objects randomly
to/from a random access file. The account information includes account number,
last name, first name, and total balance.
*/

#include <iostream>
#include <fstream>
using namespace std;

class Account {
private:
    int accountNumber;
    char lastName[20];
    char firstName[20];
    float totalBalance;

public:
    void input() {
        cout << "Enter account number: ";
        cin >> accountNumber;

        cout << "Enter first name: ";
        cin >> firstName;

        cout << "Enter last name: ";
        cin >> lastName;

        cout << "Enter total balance: ";
        cin >> totalBalance;
    }

    void display() const {
        cout << "Account No: " << accountNumber
             << ", Name: " << firstName << " " << lastName
             << ", Balance: " << totalBalance << endl;
    }
};

void addAccount() {
    Account acc;

    ofstream outFile("accounts.dat", ios::binary | ios::app);

    acc.input();
    outFile.write((char*)&acc, sizeof(acc));

    outFile.close();

    cout << "Account added successfully." << endl;
}

void displayAccounts() {
    Account acc;

    ifstream inFile("accounts.dat", ios::binary);

    cout << "\nAccount Records:" << endl;

    while (inFile.read((char*)&acc, sizeof(acc))) {
        acc.display();
    }

    inFile.close();
}

int main() {
    int choice;

    do {
        cout << "\n1. Add Account";
        cout << "\n2. Display Accounts";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
            addAccount();
        else if (choice == 2)
            displayAccounts();
        else if (choice == 3)
            cout << "Program ended." << endl;
        else
            cout << "Invalid choice." << endl;

    } while (choice != 3);

    return 0;
}