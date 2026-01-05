#include <iostream>
using namespace std;

class Person{

    string name;
    int age, weight;
};

class Student: public Person {
    int roll_number;
};

int main() {

    // Parent class propeties: private
    // Will not be inherit 
    // can not access here

    Student s1;
    // s1.name;  Not accessible
};