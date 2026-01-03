#include<iostream>
using namespace std;

class Student
{
public:
    int age;
    int roll_number;
    string name;
};

int main()
{

    Student *s = new Student;
    (*s).name = "Raman";
    (*s).age = 21;
    (*s).roll_number = 30;

    cout << s->name << endl;
    cout << (*s).name << endl;
}