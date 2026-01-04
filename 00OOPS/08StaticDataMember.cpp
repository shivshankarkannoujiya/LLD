#include <iostream>
using namespace std;

class Student
{

public:
    string name;
    static string collegeName;
    static int studentCount;

    Student(string name)
    {
        this->name = name;
        studentCount++;
    }

    void display_totalStudents(){
        cout << "Total Students: " << studentCount << endl;
    }

    void display_collegeName(){
        cout << "College Name: " << collegeName << endl;
    }
};

string Student::collegeName = "IIT Bombay";
int Student::studentCount = 0;

int main()
{

    Student s1("Raj");
    Student s2("Rajan");

    // Accessing the static member using object<Accessible but not good>
    // cout << "College Name is: " << s1.collegeName << endl;
    // cout << "College Name is: " << s2.collegeName << endl;
    // cout << "Total Student in class is: " << s1.studentCount << endl;
    // cout << "Total Student in class is: " << s2.studentCount << endl;

    // NOTE: Preferred use Class Name to access
    // cout << "College Name: " << Student::collegeName << endl;
    // cout << "Total Students: " << Student::studentCount << endl;


    // TODO: Change collegName using ClassName
    // Student::collegeName = "IIT DELHI";
    // cout << "College Name is: " << s1.collegeName << endl;
    // cout << "College Name is: " << s2.collegeName << endl;

    // TODO: Chage using obj
    // s1.collegeName = "IIT X";
    // cout << "College Name is: " << s1.collegeName << endl;
    // cout << "College Name is: " << s2.collegeName << endl;

    // TODO: print=> 15
    // s1.studentCount = 15;
    // cout << s1.studentCount << endl;
}