#include <iostream>
using namespace std;

class Car{
    protected:
        int speed;

    public:
        Car(){
            speed = 0;
        }
        
        void accelerate(){
            cout << "Accelerating..." << endl;
            speed += 20;
        }

        // POST: Speed must reudce after brake
        virtual void Brake(){
            cout << "Applying brake..." << endl;
            speed -= 20;
        }
};

class HybridCar : public Car{
    private:
        int charge;

    public:
        HybridCar() : Car(){
            charge = 0;
        }
        
        // POST:
            // 1. Speed must reduce
            // 2. Charge must increase
        void brake(){
            cout << "Applying Brake..." << endl;
            speed -= 20;
            charge += 10;
        }
};

int main() {
    Car *car = new HybridCar();
    car->Brake();
}