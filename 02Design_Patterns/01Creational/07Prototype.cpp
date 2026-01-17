#include <iostream>
#include <vector>
using namespace std;

class IPrototype {
    public:
        virtual IPrototype *clone() const = 0;
        virtual void display() const = 0;
        virtual ~IPrototype() {};
};


class Bird : public IPrototype {
    private:
        string name;
        string color;
        int weight;

    
        
    public:
        Bird() = default;

        Bird( const Bird &old){
            this->name = old.name;
            this->color = old.color;
            this->weight = old.weight;
        }


        void setName(string name){
            this->name = name;
        }

        void setColor(string color){
            this->color = color;
        }

        void setWeight(int weight){
            this->weight = weight;
        }

        virtual Bird* clone() const override {
            return new Bird(*this);
        }

        virtual void display() const override{
            cout << "Name: " << name << endl;
            cout << "Color: " << color << endl;
            cout << "Weight: " << weight << "g" << endl;
        }

        virtual ~Bird() {};
};


class Crow : public Bird {
    private:
        string sound;


    public:
        Crow() {};

        Crow (const Crow &old) : Bird(old) {
            this->sound = old.sound;
        }

        void setSound(string sound){
            this->sound = sound;
        }

        Crow* clone() const override {
            return new Crow(*this);
        }

        void display() const override{
            Bird::display();
            cout << "Sound: " << sound << endl;
        }
};


class Sparrow : public Bird {
    private:
        bool can_migrate;

    public:
        Sparrow(){}
        
        Sparrow(const Sparrow& old) : Bird(old) {
            this->can_migrate = old.can_migrate;
        }

        void setMigration(bool can_migrate){
            this->can_migrate = can_migrate;
        }

        Sparrow* clone() const override {
            return new Sparrow(*this);
        }

        void display() const override{
            Bird::display();
            cout << "Can Migrate: " << (can_migrate ? "Yes" : "No") << endl;
        }
};


int main(){

    Bird *birdOne = new Bird();

    birdOne->setName("abc");
    birdOne->setColor("white");
    birdOne->setWeight(12);

    Sparrow *sparrowOne = new Sparrow();
    sparrowOne->setName("Sparrow");
    sparrowOne->setColor("Blue");
    sparrowOne->setMigration(true);

    Crow *crowOne = new Crow();
    crowOne->setName("Crow");
    crowOne->setSound("Caw-Caw");
    crowOne->setColor("Black");
    crowOne->setWeight(34);

    vector<Bird *> birds = {
        sparrowOne,
        crowOne,
        birdOne
    };

    cout << "========== ORIGINAL BIRDS ==========" << endl;
    for (Bird *bird : birds){
        bird->display();
        cout << endl;
    }

    // TODO: Clone all birds using Prototype Pattern
    vector<Bird *> clonedBirds;
    for(Bird* bird: birds){
        clonedBirds.push_back(bird->clone());
    }

    cout << "========== CLONED BIRDS ==========" << endl;
    for (Bird *bird : clonedBirds){
        bird->display();
        cout << endl;
    }

    // TODO: Verify they are different objects
    cout << "========== MEMORY VERIFICATION ==========" << endl;
    cout << "Original Crow address: " << crowOne << endl;
    cout << "Cloned Crow address:   " << clonedBirds[1] << endl;
    cout << "Are they different objects? "
         << (crowOne != clonedBirds[1] ? "YES" : "NO") << endl;

    // TODO: Cleanup     
    for (Bird *bird : birds)
        delete bird;
    for (Bird *bird : clonedBirds)
        delete bird;

    return 0;
}
