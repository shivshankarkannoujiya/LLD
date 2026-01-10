#include <iostream>
using namespace std;

class Animal{};
class Dog : public Animal{};

class Parent{
    public:
        virtual Animal* getAnimal(){
            cout << "Parent: Retruning Animal Instance" << endl;
            return new Animal();
        }
};

class Child : public Parent{
    public:
        Dog* getAnimal(){
            cout << "Child: Retruning Dog Instance" << endl;
            return new Dog();
        }
};

class Client {
    private:
        Parent *p;
    public:
        Client(Parent *p){
            this->p = p;
        }
        
        void takeAnimal(){
            p->getAnimal();
        }
};

int main(){

    Parent *parent = new Parent();
    Child *child = new Child();

    // Client *client = new Client(parent);
    Client *client = new Client(child);

    client->takeAnimal();
}