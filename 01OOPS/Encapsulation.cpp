#include<iostream>
using namespace std;


class SportsCar {
    private:
        string brand;
        string model;
        string tyre;
        bool isEngineOn;
        int currentGear;
        int currentSpeed;

    public:    
        SportsCar(string brand, string model){
            this->brand = brand;
            this->model = model;
            tyre = "MRF";
            currentGear = 0;
            currentSpeed = 0;
            isEngineOn = false;
        }


        // getter and setter 
        int getCurrentSpeed(){
            return this->currentSpeed;
        }


        string getTyre(){
            return this->tyre;
        }

        void setTyre(string tyre){
            this->tyre = tyre;
        }

        void startEngine(){
            isEngineOn = true;
            cout << brand << " " << model << ": Engine starts with roar" << endl;
        }

        void shiftGear(int gear){
            if (!isEngineOn){
                cout << brand << " " << model << "Engine is Off! Can not shift gear" << endl;
                return;
            }

            currentGear = gear;
            cout << brand << " " << model << ": Shifted to gear " << currentGear << endl;
        }

        void accelerate(){
            if (!isEngineOn){
                cout << brand << " " << model << ": Engine is Off! Can not accelerate" << endl;
                return;
            }
            currentSpeed += 20;
            cout << brand << " " << model << ": Accelerating " << currentSpeed << " km/h" << endl;
        }

        void brake(){
            currentSpeed -= 20;
            if (currentSpeed < 0)
                currentSpeed = 0;
            cout << brand << " " << model << ": Breaking Speed now " << currentSpeed << " km/h" << endl;
        }

        void stopCar() {
            isEngineOn = false;
            currentGear = 0;
            currentSpeed = 0;
            cout << brand << " " << model << ": Engine turned Off !" << endl;
        }
};

int main(){
    SportsCar *mySportCar = new SportsCar("Ford", "Mustang");

    mySportCar->startEngine();
    mySportCar->shiftGear(1);
    mySportCar->accelerate();
    mySportCar->shiftGear(2);
    mySportCar->accelerate();
    mySportCar->brake();
    mySportCar->stopCar();

    //NOTE: Without data security: setting arbitrary value to the speed
    // Can not access directly: making it `private`
    // mySportCar->currentSpeed = 500;
    // cout << "Current speed of my Car is set to: " << mySportCar->currentSpeed << endl;

    // Access Using the `getter`
    // Only can see the speed, can not modify

    cout << mySportCar->getCurrentSpeed();

    delete mySportCar;

    return 0;
}