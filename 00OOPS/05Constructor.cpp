#include <iostream>
using namespace std;

class Customer
{

    string name;
    int age;

public:
    inline Customer(string name, int age) : name(name), age(age) {};

    Customer(const Customer &c){
        name = c.name;
        age = c.age;
    }

};

int main()
{
    Customer c1("Raj", 20);
    Customer c2(c1);
}