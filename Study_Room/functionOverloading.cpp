#include <iostream>
using namespace std;

// TODO: Study in depth

class Data
{
private:
    int value;

public:
    Data(int v) : value(v) {}

    // Non-const version
    int &getValue()
    {
        cout << "Non-const version called" << endl;
        return value;
    }

    // Const version - this IS valid overloading!
    const int &getValue() const
    {
        cout << "Const version called" << endl;
        return value;
    }
};

int main()
{
    Data data(42);
    const Data constData(100);

    data.getValue();      // Calls non-const version
    constData.getValue(); // Calls const version
}