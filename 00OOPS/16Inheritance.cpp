#include <iostream>
using namespace std;

class Parent
{
protected:
    string name;
    int age;

public:
    Parent(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void display(){
        cout << name << " | " << age << endl;
    }
};

class Child : Parent
{
private:
    int roll_number, fees;

public:
    Child(string name, int age, int roll_number, int fees) : Parent(name, age)
    {
        this->roll_number = roll_number;
        this->fees = fees;
    }

    void display()
    {
        cout << name << " | " << age << " | " << roll_number << " | " << fees << endl;
    }
};

int main()
{
    Child c1("Raj", 20, 1, 15000);
    c1.display();
}