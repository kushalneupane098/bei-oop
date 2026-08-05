#include <iostream>
using namespace std;
class ATM{
    string owner_name;
    double balance;
    static int total_transactions;
    static float total_money_moved;

    public:
        ATM(){}
        ATM(string n,double b):owner_name(n),balance(b){}
        void deposit(float amount){
            balance+=amount;

            total_transactions++;
            total_money_moved +=amount;
            cout<<owner_name<<" deposited "<<amount<<endl;
        }
        void getinput(){
            cout<<"Enter the name please: ";
            cin>>owner_name;
            balance = 100000;
            
        }
        void withdraw(float amount){
            if(amount<=balance){
                balance-=amount;

                total_transactions++;
                total_money_moved+=amount;

                cout<<owner_name<<" withdrew "<<amount<<endl;
            }
            else{
                cout<<"Insufficient balance"<<endl;
            }
        }
        void showbalance(){
            cout<<"Name: "<<owner_name<<endl;
            cout<<"Balance: "<<balance<<endl;
        }

        void static showstatus(){
            cout<<"----ATM STATISTICS----"<<endl;
            cout<<"Total Transactions "<<total_transactions<<endl;
            cout<<"Total Money Moved "<<total_money_moved;
        }

          
};
int ATM::total_transactions = 0;
float ATM::total_money_moved = 0.0;
int main(){
    ATM user1;
    ATM user2;
    user1.getinput();
    char choice;
    cout<<"(d) for deposit and (w) for withdraw: ";
    cin>>choice;
    float depamt, witamt;
    if(choice == 'd'||choice == 'D'){
        cout<<"Enter the amount you wanna deposit: ";
        cin>>depamt;
        user1.deposit(depamt);
    }
    else if(choice == 'w'||"W"){
        cout<<"Enter the amount you wanna withdraw: ";
        cin>>witamt;
        user1.withdraw(witamt);
    }
    user1.showbalance();
    user1.showstatus();
    cout<<endl;
    cout<<"Welcome user "<<endl;


    user2.getinput();
    char choice2;
    cout<<"(d) for deposit and (w) for withdraw: ";
    cin>>choice2;
    float depamt1, witamt1;
    if(choice2 == 'd'||choice2 == 'D'){
        cout<<"Enter the amount you wanna deposit: ";
        cin>>depamt1;
        user2.deposit(depamt1);
    }
    else if(choice == 'w'||"W"){
        cout<<"Enter the amount you wanna withdraw: ";
        cin>>witamt1;
        user2.withdraw(witamt1);
    }
    user2.showbalance();
    user2.showstatus();
    return 0;
}