#include <iostream>
using namespace std;

class Person
{
private:
    int a;

protected:
    int b;

public:
    int c;

    // Accessing within class, can access with the same class
    void init()
    {
        a = 10;
        b = 20;
        c = 30;
    }
};

int main()
{

    Person Aman;
    // Aman.a;  Can not Access from from external code
    // Aman.b; Can not Access from from external code
    Aman.c = 10;
}