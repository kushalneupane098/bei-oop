#include <iostream>
#include <fstream>
using namespace std;

struct Account {
    int accNum;
    char lastName[20];
    char firstName[20];
    double balance;
};

int main() {
    ifstream check("credit.dat", ios::binary);
    if (!check) {
        ofstream out("credit.dat", ios::binary);
        Account blank = {-1, "", "", 0.0};
        for (int i = 0; i < 100; i++) {
            out.write(reinterpret_cast<char*>(&blank), sizeof(Account));
        }
        out.close();
    }
    if (check) check.close();

    fstream file("credit.dat", ios::in | ios::out | ios::binary);
    int choice, r;
    Account acc;

    do {
        cout << "\n1.Add 2.Display 3.Update 4.Delete 5.Exit: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter slot (1-100): "; cin >> r;
            acc.accNum = r;
            cin >> acc.firstName >> acc.lastName >> acc.balance;
            file.seekp((r - 1) * sizeof(Account));
            file.write(reinterpret_cast<char*>(&acc), sizeof(Account));
        } 
        else if (choice == 2) {
            file.seekg(0, ios::beg);
            while (file.read(reinterpret_cast<char*>(&acc), sizeof(Account))) {
                if (acc.accNum != -1) {
                    cout << acc.accNum << " " << acc.firstName << " " << acc.lastName << " " << acc.balance << endl;
                }
            }
            file.clear();
        } 
        else if (choice == 3) {
            cout << "Enter slot: "; cin >> r;
            file.seekg((r - 1) * sizeof(Account));
            file.read(reinterpret_cast<char*>(&acc), sizeof(Account));
            if (acc.accNum != -1) {
                cout << "Enter new balance: "; cin >> acc.balance;
                file.seekp((r - 1) * sizeof(Account));
                file.write(reinterpret_cast<char*>(&acc), sizeof(Account));
            }
        } 
        else if (choice == 4) {
            cout << "Enter slot: "; cin >> r;
            Account blank = {-1, "", "", 0.0};
            file.seekp((r - 1) * sizeof(Account));
            file.write(reinterpret_cast<char*>(&blank), sizeof(Account));
        }
    } while (choice != 5);

    file.close();
    return 0;
}