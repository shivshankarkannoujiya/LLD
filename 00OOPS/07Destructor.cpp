#include <iostream>
using namespace std;

class Customer
{

    string name;
    int *data;

public:

    Customer(){
        name = "4";
        cout << "Constructor called for " << name << endl;
    }

    Customer(string name)
    {
        this->name = name;
        cout << "Constructor called for " << name << endl;
    }

    ~Customer()
    {
        cout << "Destructor called for " << name << endl;
    }
};

int main()
{
    Customer c1("1"), c2("2"), c3("3");
    Customer *c4 = new Customer;

    // for: c4 destructor will not run
    // Call manually
    delete c4;
}