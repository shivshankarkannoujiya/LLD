#include <iostream>
using namespace std;


class Area {

    public:
        int calculateArea(int radius){
            return 3.14 * radius * radius;
        }

        int calculateArea(int length, int breadth){
            return length * breadth;
        }
};

int main(){
    Area A1, A2;
    cout << "Area is: " << A1.calculateArea(4) << endl;
    cout << "Area is: " << A2.calculateArea(4, 4) << endl;
}