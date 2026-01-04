#include <iostream>
using namespace std;

class Wallet
{

private:
    string name;
    double balance;

public:
    Wallet(string name)
    {
        this->name = name;
        balance = 0;
    }

    // 2. CONTROLLED ACCESS (The Teller Window)
    void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "Error: Cannot deposit negative money" << endl;
            return;
        }
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    // 3. LOGIC ENFORCEMENT
    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Error: Insufficient balance!" << endl;
            return;
        }
        balance -= amount;
        cout << "Withdrew: " << amount << endl;
    }

    double getBalance()
    {
        return balance;
    }
};

int main()
{
    Wallet *w1 = new Wallet("Aman");

    w1->deposit(10000);
    cout << "Balance is: " << w1->getBalance() << endl;

    w1->withdraw(1000);
    cout << "Balance is: " << w1->getBalance() << endl;
}