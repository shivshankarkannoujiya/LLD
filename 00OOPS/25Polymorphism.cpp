#include <iostream>
using namespace std;

class Animal
{

public:
    virtual void speak()
    {
        cout << "Some generic animal voice" << endl;
    }
};

class Dog : public Animal
{

public:
    void speak()
    {
        cout << "Woof! Woof!" << endl;
    }
};

int main()
{
    Animal *p;
    p = new Dog();
    p->speak();
}