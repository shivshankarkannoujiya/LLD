#include <iostream>
using namespace std;

class Customer
{

    string name;
    int acc_number;
    int balance;

public:
    Customer(
        string name,
        int acc_number,
        int balance)
    {
        this->name = name;
        this->acc_number = acc_number;
        this->balance = balance;
    }

    // NOTE: inline constructor
    inline Customer(string name, int balance) : name(name), balance(balance) {}

    void printDetails(){
        cout << name << " | Balance: " << balance << endl;
    }
};

int main()
{
    Customer *c1 = new Customer("Raman", 1234, 1000);
    Customer *c2 = new Customer("Rajan", 1235, 10000);

    Customer c3("Ajay", 1000);
    c3.printDetails();
}