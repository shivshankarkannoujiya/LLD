#include <iostream>
using namespace std;

enum class TransportMode{
    CAR,
    BIKE,
    WALK
};


class GoogleMap{

    public:
        void findPath(string from, string to, TransportMode mode){
            if(mode == TransportMode::CAR){
                cout << "Finding path for Car..." << endl;
            }else if(mode == TransportMode::WALK){
                cout << "Finding path for Walk..." << endl;
            }else if (mode == TransportMode::BIKE){
                cout << "Finding path for Bike..." << endl;
            }
        }
};
