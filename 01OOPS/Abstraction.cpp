#include <iostream>
using namespace std;


class Car {
    public:   
        virtual void startEngine() = 0;
        virtual void shiftGear(int gear) = 0;
        virtual void accelerate() = 0;
        virtual void brake() = 0;
        virtual void stopCar() = 0;

        virtual ~Car() {};
};

class SportsCar: public Car {
    public:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;

        SportsCar(string brand, string model){
            this->brand = brand;
            this->model = model;
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
        }

        // NOTE: For driving Car the Users no need to know this internal working of Car
        void startEngine(){
            isEngineOn = true;
            cout << brand << " " << model << ": Engine starts with roar" << endl;
        }

        void shiftGear(int gear) {
            if(!isEngineOn){
                cout << brand << " " << model << "Engine is Off! Can not shift gear" << endl;
                return;
            }

            currentGear = gear;
            cout << brand << " " << model << ": Shifted to gear " << currentGear << endl;
        }

        void accelerate(){
            if(!isEngineOn){
                cout << brand << " " << model << ": Engine is Off! Can not accelerate" << endl;
                return;
            }
            currentSpeed += 20;
            cout << brand << " " << model << ": Accelerating " << currentSpeed  << " km/h" << endl;
        }

        void brake() {
            currentSpeed -= 20;
            if(currentSpeed < 0)
                currentSpeed = 0;
            cout << brand << " " << model << ": Breaking Speed now " << currentSpeed << " km/h" << endl;
        }
        void stopCar() {
            isEngineOn = false;
            currentGear = 0;
            currentSpeed = 0;
            cout << brand << " " << model << ": Engine turned Off !"<< endl;
        }
};

int main(){
    cout << "Learning Abstraction..."<<endl;

    Car *newCar = new SportsCar("Ford", "Mustang");

    newCar->startEngine();
    newCar->shiftGear(1);
    newCar->accelerate();
    newCar->shiftGear(2);
    newCar->brake();
    newCar->stopCar();

    delete newCar;

    return 0;
}