#include <iostream>
using namespace std;

class Person
{

protected:
    string name;
    int age;

public:
    void introduce()
    {
        cout << "Hello my name is " << name << endl;
    }
};

class Employee : public Person
{

protected:
    int salary;

public:
    void monthly_salary()
    {
        cout << "My monthly salary is " << salary << endl;
    }
};

class Manager : public Employee
{

private:
    string department;
    int no_of_employee;

public:
    Manager(
        string name,
        int age,
        int salary,
        string department,
        int no_of_employee)
    {
        this->name = name;
        this->age = age;
        this->salary = salary;
        this->department = department;
        this->no_of_employee = no_of_employee;
    }

    void work()
    {
        cout << "I am leading the department " << department << " with " << no_of_employee << " employee" << endl;
    }
};

int main()
{
    Manager m1("Raman", 20, 1200000, "Finance", 12);
    m1.introduce();
    m1.work();
    m1.monthly_salary();
}