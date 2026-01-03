// TODO: Access Private properties
// NOTE: getter and setter

#include <iostream>
using namespace std;


class Student {

    string name;
    int age;
    int roll_number;
    string grade;

    public:
        void setName(string n) {

            // PROS: Can put checks before taking input from user 
            if (n.size() == 0){
                cout << "INVALID NAME" << endl;
                return;
            }
            name = n;
        }

        void setAge(int a){
            if (age < 0 || age > 100){
                cout << "INVALID AGE" << endl;
                return;
            }
            age = a;
        }

        string getName(){
            return name;
        }

        int getAge(){
            return age;
        }

        // TODO: Show the grade to someone if her entered the ROLL_NUMBER
        string show_grade(int roll_number){
            if (roll_number != 12334){
                cout << "INVALID ROLL NUMBER";
                return;
            }

            return grade;
        }
    };


int main(){
    Student s1;
    s1.setName("Mohan");
    s1.setAge(10);

    string name = s1.getName();
    int age = s1.getAge();

    cout << "Name is: " << name << " Age is: " << age << endl;
}