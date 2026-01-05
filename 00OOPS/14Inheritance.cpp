#include <iostream>
using namespace std;

class Person
{
private:
    string Religion, color;

public:
    string name;
    int age, weight;
};

class Student : protected Person
{

    int roll_number, fees;

public:
    Student(string name, int age, int weight, int roll_number, int fees)
    {
        this->name = name;
        this->age = age;
        this->weight = weight;
        this->roll_number = roll_number;
        this->fees = fees;
    }

    void printStudentDetails()
    {
        cout << "Student details: " << name << " | " << age << " | " << weight << " | " << roll_number << " | " << fees << endl;
    }
};

class Teacher : private Person
{

private:
    int salary, id;

public:
    Teacher(int id, string name, int age, int weight, int salary)
    {
        this->id = id;
        this->name = name;
        this->age = age;
        this->weight = weight;
        this->salary = salary;
    }

    void printTeacherDetails()
    {
        cout << "Teacher details: " << id << " | " << name << " | " << age << " | " << weight << " | " << salary << endl;
    }
};

int main()
{
    Student s1("Raj", 21, 70, 101, 30000);
    s1.printStudentDetails();

    Teacher t1(1, "Raman", 80, 90, 1000000);
    t1.printTeacherDetails();
}