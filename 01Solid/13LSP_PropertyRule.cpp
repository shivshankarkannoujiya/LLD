#include <iostream>
using namespace std;



class BankAccount{
    protected:
        double balance;

    public:
        BankAccount(double initialBalance){
            if(initialBalance < 0)
                throw invalid_argument("Balance can not be negative");
            this->balance = balance;
        }
        
        // Withdrawal should be allowed
        virtual void withdraw(double amount){
            if(amount > balance)
                throw runtime_error("Insufficient balance");
            balance -= amount;
            cout << "Amount withdrawn, Remaining balance is: " << balance << endl;
        }
};

class FixedDepositeAccount : public BankAccount{
    public:
        FixedDepositeAccount(double balance) : BankAccount(balance) {};

        // History Constraints Break!
        // Parent class behaviour change : not withdrawal not allowed
        // This class will break client code that relies on withdrawal
        void withdraw(double amount) override {
            throw runtime_error("Withdraw is not allowed in Fixed Deposite");
        }
};


int main(){
    BankAccount *bank = new BankAccount(1000);
    bank->withdraw(200);
}
