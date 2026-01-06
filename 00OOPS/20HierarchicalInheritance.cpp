#include <iostream>
using namespace std;

// ------------------ The University System ----------------

class Person
{

protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {};

    void introduce()
    {
        cout << "My name is: " << name << endl;
    }
};

class Student : public Person
{

private:
    int roll_number, fees;

public:
    Student(string name, int age, int r, int f) : Person(name, age),
                                                  roll_number(r), fees(f) {};

    void study()
    {
        introduce();
        cout << roll_number << " | " << fees << endl;
    }
};

class Professor : public Person
{

private:
    int salary;

public:
    Professor(string name, int age, int s) : Person(name, age), salary(s) {};

    void teach()
    {
        introduce();
        cout << " and I am teaching C++." << " | " << "Salary is: " << salary << endl;
    }
};


int main(){

    Student s1("Rahul", 20, 1, 12000);
    Professor p1("Dr. Sharma", 80, 12000000);

    s1.study();
    p1.teach();
}