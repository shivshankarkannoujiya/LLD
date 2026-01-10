#include <iostream>
using namespace std;


// Invarient: balance can not be negative
class BankAccount {

    protected:
        double balance;

    public:
        BankAccount(double initialBalance){
            if(initialBalance < 0)
                throw invalid_argument("Balance can not be negative");
            this->balance = initialBalance;
        }    

        virtual void withdraw(double amount){
            if(amount > balance)
                throw runtime_error("Insufficient fund");
            balance -= amount;
            cout << "Amount withdrawn, Remaining balance is: " << balance << endl;
        }
};

// Breaking invarient: Should not be allowed
class CheatAccount : public BankAccount {
    public:
        CheatAccount(double balance) : BankAccount(balance) {};

        void withdraw(double amount) override {
            balance -= amount; // Invarient Break! Negative balance is allowed
            cout << "Amount withdrawn, Remaining balance is: " << balance << endl;
        }
};

int main(){
    BankAccount *bank = new BankAccount(1000);
    bank->withdraw(200);
}