#include <iostream>
using namespace std;

class Shape
{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

class Square : public Shape{
private:
    double side;

public:
    Square(double s) : side(s) {}

    double area() override{
        return side * side;
    }

    // Unnecessary
    double volume() override{
        throw logic_error("Volume is not applicable for Square");
    }
};

class Rectangle : public Shape{
    private:
        double length, width;
    
    public:
        Rectangle(double l, double w) : length(l), width(w) {};

        double area() override {
            return length * width;
        }

        // Unnecessary
        double volume() override{
            throw logic_error("Volume is not applicable for Rectangle");
        }
};

class Cube : public Shape{
    private:
        double side;

    public:
        Cube(double s) : side(s) {};

        double area() override {
            return 6 * side * side;
        };
        double volume() override {
            return side * side * side;
        };
};

int main() {
    Shape *square = new Square(5);
    Shape *rectangle = new Rectangle(5, 7);
    Shape *cube = new Cube(2);

    square->area();
    rectangle->area();
    cube->area();
    cube->volume();

    try{
        square->volume();
    }catch(const logic_error &e){
        cerr << "Exception: " << e.what() << endl;
    }
}