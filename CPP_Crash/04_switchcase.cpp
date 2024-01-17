#include <iostream>
using namespace std;

int main()
{

    char grade;
    cout << "Enter your grade : ";
    cin >> grade;

    switch (grade)
    {

    case 'A':
        cout << "Marks range is 0 to 90" << endl;
        break;
    case 'B':
        cout << "Marks range is 0 to 80" << endl;
        break;
    case 'C':
        cout << "Marks range is 0 to 70" << endl;
        break;
    case 'D':
        cout << "Marks range is 0 to 60" << endl;
        break;
    default:
        cout << "Marks range is 0 to 50" << endl;
    }
}