#include <iostream>
using namespace std;

int main()
{

    int age;
    cout << "Enter age : ";
    cin >> age;
    // if (age > 18)
    // {
    //     cout << "Can Vote" << endl;
    // }
    // else
    // {
    //     cout << "Can not Vote" << endl;
    // }

    (age > 18) ? cout << "Can Vote" << endl : cout << "Can not Vote" << endl;

    int x = 20;
    int y = 30;
    int result = (x > y) ? x : y;
    cout << "Ans is : " << result << endl;
}