#include <iostream>
using namespace std;

class GrandParent
{
protected:
    string name;
    int age;

public:
    GrandParent(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void grand()
    {
        cout << "I am grand parent" << endl;
    }
};

class Parent : public GrandParent
{
private:
    string occupation;

public:
    Parent(string name, int age, string occupation) : GrandParent(name, age)
    {
        this->occupation = occupation;
    }
};

class Child : public Parent
{
    int roll_number, fees;

public:
    Child(
        string name,
        int age,
        string occupation,
        int roll_number,
        int fees) : Parent(name, age, occupation)
    {
        this->roll_number = roll_number;
        this->fees = fees;
    }
};

int main()
{
    Child c1("Raman", 12, "Student", 1, 120000);
}