#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class IPrototype{
public:
    virtual IPrototype *clone() const = 0;
    virtual void display() const = 0;
    virtual ~IPrototype() {}
};

class Bird : public IPrototype{
private:
    string name;
    string color;
    int weight;

public:
    Bird(){}

    Bird(const Bird &old){
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

    virtual Bird *clone() const override{
        return new Bird(*this);
    }

    virtual void display() const override{
        cout << "Bird - Name: " << name << endl;
        cout << "Color: " << color << endl;
        cout<< "Weight: " << weight << "g" << endl;
    }

    virtual ~Bird() {}
};

class Crow : public Bird{
private:
    string sound;

public:
    Crow(){}

    Crow(const Crow &old) : Bird(old){
        this->sound = old.sound;
    }

    void setSound(string sound){
        this->sound = sound;
    }

    Crow *clone() const override{
        return new Crow(*this);
    }

    void display() const override{
        Bird::display();
        cout << "Sound: " << sound << endl;
    }
};

class Sparrow : public Bird{
private:
    bool can_migrate;

public:
    Sparrow(){}

    Sparrow(const Sparrow &old) : Bird(old){
        this->can_migrate = old.can_migrate;
    }

    void setMigration(bool can_migrate){
        this->can_migrate = can_migrate;
    }

    Sparrow *clone() const override{
        return new Sparrow(*this);
    }

    void display() const override{
        Bird::display();
        cout << "Can Migrate: " << (can_migrate ? "Yes" : "No") << endl;
    }
};

class BirdRegistry {
    private:
        unordered_map<string, Bird *> birds_prototypes;

    public:
        void registerBird(string name, Bird* bird){
            birds_prototypes[name] = bird;
            cout << "Registered prototype: " << name << endl;
        }

        Bird* getBird(const string& name){
            auto it = birds_prototypes.find(name);
            if(it != birds_prototypes.end()){
                return it->second->clone();
            }
            return nullptr;
        }

};

int main(){}