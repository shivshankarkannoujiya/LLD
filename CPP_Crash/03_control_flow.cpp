#include <iostream>
using namespace std;

int main()
{

    int budget;
    cout << "Enter your budget : ";
    cin >> budget;

    if (budget > 200000)
    {
        cout << "You can buy scorpio" << endl;
    }
    else
    {
        cout << "You can not buy scorpio" << endl;
    }

    int marks = 55;
    if (marks > 90)
    {
        cout << 'A' << endl;
    }
    else if (marks > 80)
    {
        cout << 'B' << endl;
    }
    else if (marks > 70)
    {
        cout << 'C' << endl;
    }
    else if (marks > 60)
    {
        cout << 'D' << endl;
    }
    else
    {
        cout << "Unable to fetch grade" << endl;
    }

    return 0;
}