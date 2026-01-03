#include <iostream>
using namespace std;

class Customer
{

    string name;
    int *balance;

public:
    Customer(string name, int balance)
    {
        this->name = name;
        this->balance = new int;
        *this->balance = balance;
    }

    ~Customer()
    {
        cout << "Destructor called" << endl;
        delete balance;
    }
};

int main()
{
    Customer *c1 = new Customer("Raman", 1000);
}