#include <iostream>
using namespace std;

class Person{
    public:
        string name;
        Person(){
            cout << "Person created successfully"<<endl;
        }
};


class Student: virtual public Person
{
    public:
        Student(){
            cout << "Student created successfully"<<endl;
        }
};

class Teacher: virtual public Person
{
public:
    Teacher()
    {
        cout << "Teacher created successfully"<<endl;
    }
};

class TeachingAssistant: public Student, public Teacher{

public:    
    TeachingAssistant(string name){
        this->name = name;
        cout << "TA created successfully"<<endl;
    }

    void printDetails(){
        cout << "Name: " << name << " (No Ambiguity!)" << endl;
    }
};

int main(){
    TeachingAssistant mTA("Raman");
    mTA.printDetails();
}