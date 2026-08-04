#include<iostream>
using namespace std;
class ATM {
    private:
        string name;
        float bal;
        static int totalTrans;
        static float totalMoney;

    public:
        ATM(string n, float b) {
            name = n;
            bal  = b;
        }
        void deposit(float amt) {
            bal += amt;
            totalTrans++;
            totalMoney += amt;
        }
        void withdraw(float amt) {
            if(amt <= bal) {
                bal -= amt;
                totalTrans++;
                totalMoney += amt;
            } else {
                cout << "Not enough balance!" << endl;
            }
        }
        void show() {
            cout << "Name    : " << name << endl;
            cout << "Balance : Rs." << bal  << endl;
        }
        static void showStats() {
            cout << "Total Transactions : " << totalTrans << endl;
            cout << "Total Money Moved  : Rs." << totalMoney << endl;
        }
};
int ATM::totalTrans  = 0;
float ATM::totalMoney = 0;
int main() {
    ATM a1("Bisesh", 10000);
    ATM a2("Hari",   5000);
    a1.deposit(2000);
    a1.withdraw(1000);
    a2.deposit(1000);
    a2.withdraw(500);
    cout << "Account 1" << endl;
    a1.show();
    cout << endl << "Account 2" << endl;
    a2.show();
    cout << endl << "ATM Stats" << endl;
    ATM::showStats();
    return 0;
}
