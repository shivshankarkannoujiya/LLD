#include <iostream>
#include <vector>
using namespace std;

class Account{
    public:
        virtual void deposite(double amount) = 0;
        virtual void withdraw(double amount) = 0;
};


class SavingAccount : public Account {

    private:
        double balance;
    public:

        SavingAccount(){
            balance = 0;
        }
        
        void deposite(double amount) override {
            if(amount > 0){
                balance += amount;
                cout << "Deposited: " << amount << " in saving account. New Balance is: " << balance << endl;
            }else{
                cout << "Balance should be grater than 0 for deposite" << endl;
            }
        }

        void withdraw(double amount) override{
            if (balance >= amount){
                balance -= amount;
                cout << "Withdrawal: " << amount << " in saving account. New Balance is: " << balance << endl;
            }else{
                cout << "insufficient balance in saving account" << endl;
            }    
        }
};

class CurrentAccount : public Account {

    private:
        double balance;
    public:
        CurrentAccount(){
            balance = 0;
        }

        void deposite(double amount) override {
            if(amount > 0){
                balance += amount;
                cout << "Deposited: " << amount << " in current account. New Balance is: " << balance << endl;
            }else{
                cout << "Balance should be grater than 0 for deposite" << endl;
            }
        }

        void withdraw(double amount) override{
            if (balance >= amount){
                balance -= amount;
                cout << "Withdrawal: " << amount << " in current account. New Balance is: " << balance << endl;
            }else{
                cout << "insufficient balance in current account" << endl;
            }    
        }
};

class FixedDepositeAccount : public Account {

    private:
        double balance;

    public:
        FixedDepositeAccount(){
            balance = 0;
        }

        void deposite(double amount) override{
            if (amount > 0){
                balance += amount;
                cout << "Deposited: " << amount << " in FD account. New Balance is: " << balance << endl;
            }
            else{
                cout << "Balance should be grater than 0 for deposite" << endl;
            }
        }

        void withdraw(double amount) override{
            throw logic_error("Withdrawal is not allowed in Fixed Deposite Account");
        }
};

class BankClient{
    private:
        vector<Account *> accounts;

    public:    
        BankClient(vector<Account*> accounts){
            this->accounts = accounts;
        }

        void processTransaction(){
            for(Account* acc : accounts){
                acc->deposite(1000);

                // NOTE: Assuming all typeof account supports: withdraw
                // but, FixedDepositeAccount not follow the rule
                // BRREAKING: LSP
                try{
                    acc->withdraw(100);
                }
                catch(const logic_error& e){
                    cout << "Exception: " << e.what() << endl;
                }
                
            }
        }
};

int main(){
    vector<Account *> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedDepositeAccount());

    BankClient *client = new BankClient(accounts);
    client->processTransaction();
}