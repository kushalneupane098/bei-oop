#include<iostream>
using namespace std;
class ATM {
    private:
        string ownerName;
        float balance;
        static int totalTransactions;
        static float totalMoneyMoved;
       
        
    public:
     
        ATM(string name,float amount){
            ownerName=name;
            balance=amount;
        }

   void deposit(){
        float amount=0;
        cout<<"ENTER AMOUNT";
        cin>>amount;
        balance+=amount;
        totalTransactions++;
        totalMoneyMoved+=amount;
    }
   void  withdraw(){
        float amount=0;
        cout<<"Enter amount";
        cin>>amount;
        if(balance>amount){
        balance-=amount;
        totalTransactions++;
        totalMoneyMoved+=amount;
        }else{
            cout<<"NO money";
        }

    }
    static void showStats(){
         cout<<"Total transaction :"<<totalTransactions<<"\n\n";
           cout<<"Total transaction :"<<totalMoneyMoved<<"\n";
    }

};
int ATM::totalTransactions=0;
float ATM::totalMoneyMoved=0;
int main(){
    int a;
    ATM a1("hari",20000);
    do{
    cout<<"#CHOOSE YOUR OPTIONS#"<<"\n"<<"1.Deposit Money"<<"\n"<<"2.Withdraw Monye"<<"\n"<<endl;
    cout<<"3.SHOW STATUS"<<"\n"<<"4.QUIT"<<endl;
    cin>>a;
        switch(a){
    case 1:
                 a1.deposit();
                 break;
        case 2:
                  a1.withdraw();
                 break;
    case 3:
    
                ATM::showStats();
                break;
    case 4:
                 cout<<"exiting";
                 break;
     default:
                 cout<<"INVALID CHOICE";
   break;
}
}while(a!=4);
   
   return 0;
}