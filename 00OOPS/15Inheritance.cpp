#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person()
    {
        cout << "Parent constructor called..." << endl;
    }

    void work()
    {
        cout << "I am working" << endl;
    }

    ~Person()
    {
        cout << "Parent Destructor called..." << endl;
    }
};

class Student : public Person
{
    int roll_number, fees;

public:
    Student(
        string name,
        int age,
        int roll_number,
        int fees)
    {
        this->name = name;
        this->age = age;
        this->roll_number = roll_number;
        this->fees = fees;
        cout << "Child constructor called..." << endl;
    }

    ~Student()
    {
        cout << "Child Destructor called..." << endl;
    }
};

int main()
{
    Student s1("Rohan", 20, 1, 15000);
}