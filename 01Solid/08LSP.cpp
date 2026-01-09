#include <iostream>
#include <vector>
using namespace std;

class DepositeOnlyAccount{
    public:
        virtual void deposite(double amount) = 0;
};

class WithdrawableAccount : public DepositeOnlyAccount{
    public:
        virtual void withdraw(double amount) = 0;
};


class SavingAccount : public WithdrawableAccount {
    private:
        double balance = 0;


    public:
        SavingAccount(){
            balance = 0;
        }

        void deposite(double amount) override{
            if (amount > 0){
                balance += amount;
                cout << "Deposited: " << amount << " in saving account. New balance is: " << balance << endl;
            }
            else{
                cout << "Amount should be greater than 0" << endl;
            }
        }

        void withdraw(double amount) override{
            if (balance >= amount){
                balance -= amount;
                cout << "Withdrawal: " << amount << " from saving account. New balance is: " << balance << endl;
            }
            else{
                cout << "insufficient balance is saving account" << endl;
            }
        }
};

class CurrentAccount : public WithdrawableAccount {
    private:
        double balance = 0;


    public:
        CurrentAccount(){
            balance = 0;
        }

        void deposite(double amount) override{
            if (amount > 0){
                balance += amount;
                cout << "Deposited: " << amount << " in current account. New balance is: " << balance << endl;
            }
            else{
                cout << "Amount should be greater than 0" << endl;
            }
        }

        void withdraw(double amount) override{
            if (balance >= amount){
                balance -= amount;
                cout << "Withdrawal: " << amount << " from current account. New balance is: " << balance << endl;
            }
            else{
                cout << "insufficient balance is current account" << endl;
            }
        }
};


class FixedDepositeAccount : public DepositeOnlyAccount {
    private:
        double balance;

    public:
        FixedDepositeAccount(){
            balance = 0;
        }

        void deposite(double amount) override{
            if (amount > 0){
                balance += amount;
                cout << "Deposited: " << amount << " in FD account. New balance is: " << balance << endl;
            }
            else{
                cout << "Amount should be greater than 0" << endl;
            }
        }
};

class BankClient {

    private:
        vector<DepositeOnlyAccount *> depositeOnlyAccounts;
        vector<WithdrawableAccount *> withdrawableAccounts;

    public:
        BankClient(
            vector<DepositeOnlyAccount *> depositeOnlyAccounts,
            vector<WithdrawableAccount *> withdrawableAccounts
        ) {
            this->depositeOnlyAccounts = depositeOnlyAccounts;
            this->withdrawableAccounts = withdrawableAccounts;
        }
    
        void processTransaction(){
            for(WithdrawableAccount *acc : withdrawableAccounts){
                acc->deposite(1000);
                acc->withdraw(100);
            }
            for(DepositeOnlyAccount *acc : depositeOnlyAccounts){
                acc->deposite(5000);
            }
        }
};

int main(){

    
    vector<WithdrawableAccount *> withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingAccount());
    withdrawableAccounts.push_back(new CurrentAccount());
    
    vector<DepositeOnlyAccount *> depositeOnlyAccounts;
    depositeOnlyAccounts.push_back(new FixedDepositeAccount());

    BankClient *client = new BankClient(depositeOnlyAccounts, withdrawableAccounts);
    client->processTransaction();
}