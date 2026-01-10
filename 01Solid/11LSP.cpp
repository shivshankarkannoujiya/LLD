#include <iostream>
using namespace std;


class Parent {
    public:
        virtual void getValue() noexcept(false) {
            throw logic_error("Parent Error");
        }
};


class Child : public Parent {
    void getValue() noexcept(false) override {
        throw out_of_range("Child Error");
    }
};

class Client {
    private:
        Parent *p;
    
    public:
        Client(Parent *p){
            this->p = p;
        }
        
        void takeValue(){
            try{
                p->getValue();
            }
            catch(const logic_error &e){
                cerr << "Logical Error Exception occured " << e.what() << endl;
            }
            
        }
};

int main(){
    Parent *parent = new Parent();
    Child *child = new Child();

    Client *client = new Client(child);
    client->takeValue();
}