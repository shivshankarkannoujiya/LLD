#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    string grade;
    int age;
    int roll_no;
};

int main()
{

    Student s1;
    s1.name = "Rohan";
    s1.grade = "A+";
    s1.age = 20;
    s1.roll_no = 30;

    Student s2;
    s2.name = "Mohan";
    s2.grade = "A+";
    s2.age = 22;
    s2.roll_no = 31;
}