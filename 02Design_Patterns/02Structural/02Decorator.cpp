#include <iostream>
using namespace std;

// <<Abstract>>
class IceCreamCone {
    public:
        virtual int getCost() = 0;
        virtual string getConstituents() = 0;
};


class OrangeCone : public IceCreamCone {
    public:
        int getCost() override {
            return 10;
        }

        string getConstituents() override {
            return "Orange_Cone";
        }
};


class BlueCone : public IceCreamCone {
    public:
        int getCost() override {
            return 5;
        }

        string getConstituents() override {
            return "Blue_Cone";
        }
};


class VanillaScoop : public IceCreamCone{

    private:
        IceCreamCone *iceCreamCone;

    public:
        VanillaScoop(IceCreamCone *iceCreamCone){
            this->iceCreamCone = iceCreamCone;
        }

        int getCost() override{
            return iceCreamCone->getCost() + 15;
        }

        string getConstituents() override{
            return iceCreamCone->getConstituents() + "," + "Vanilla";
        }
};


class ChocolateScoop : public IceCreamCone{
    private:
        IceCreamCone *iceCreamCone;

    public:
        ChocolateScoop(IceCreamCone *iceCreamCone){
            this->iceCreamCone = iceCreamCone;
        }

        int getCost() override{
            return iceCreamCone->getCost() + 32;
        }

        string getConstituents() override{
            return iceCreamCone->getConstituents() + "," +  "Chocolate";
        }
};


int main(){
    IceCreamCone *iceCreamCone =
    new VanillaScoop(new ChocolateScoop(
            new VanillaScoop(
                new OrangeCone()
            )
        )
    );

    // TODO: want to create
    // Chocobar: Blue_Cone + 2 ChocoScoop
    // KesarPista: Blue_Cone + 1 VanillaScoop

    IceCreamCone *chocobar = new ChocolateScoop(new ChocolateScoop(new BlueCone()));
    IceCreamCone *kesarPista = new VanillaScoop(new BlueCone());

    // NOTE: 1 Person says: I want to get Chocobar with 1 VanillaScoop to Chocobar
    // - Use same chocobar object
    // - Not creating new object 

    IceCreamCone *chocoWithOneVanilla = new VanillaScoop(chocobar);

    cout << chocoWithOneVanilla->getCost() << endl;
    cout << chocoWithOneVanilla->getConstituents() << endl;
}

/*
    NOTE: Usecase: <Interview>
    - Pizza: Building Pizza Ordering system
    - Coffee Machine System: 
                    - Have a coffee decorate with
                        - Milk
                        - Chocos etc.
    - UI Components
    NOTE: DECORATING THINGS FROM `BELOW` -> `UP`
*/