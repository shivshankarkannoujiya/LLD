#include <iostream>
#include <vector>
#include<typeinfo>
using namespace std;

class Account{
public:
    virtual void deposite(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public Account{
private:
    double balance;

public:
    void deposite(double amount) override {
        if(amount > 0){
            balance += amount;
            cout << "Deposited: " << amount << " in saving account. New balance is: " << balance << endl;
        }else{
            cout << "Amount should be greater than 0" << endl;
        }
    }

    void withdraw(double amount) override {
        if(balance >= amount){
            balance -= amount;
            cout << "Withdrawal: " << amount << " from saving account. New balance is: " << balance << endl;
        }else{
            cout << "insufficient balance is saving account" << endl;
        }
    }
};

class CurrentAccount : public Account{
private:
    double balance;

public:
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

class FixedDepositeAccount : public Account{
private:
    double balance;

public:
    void deposite(double amount) override{
        if (amount > 0){
            balance += amount;
            cout << "Deposited: " << amount << " in Fixed Deopiste account. New balance is: " << balance << endl;
        }
        else{
            cout << "Amount should be greater than 0" << endl;
        }
    }

    void withdraw(double amount) override {
        throw logic_error("Withdrawal is not allowed to the Fixed Deopiste Account");
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

                if(typeid(*acc) == typeid(FixedDepositeAccount)){
                    cout << "Skipping Withdrawal for Fixed Deposite Account" << endl;
                }else{
                    try{
                        acc->withdraw(100);
                    }catch(const logic_error& e){
                        cout << "Exception: " << e.what() << endl;
                    }
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
