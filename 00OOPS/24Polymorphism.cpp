#include <iostream>
using namespace std;

class Complex
{

private:
    int real, imag;

public:
    // Complex(){
    //     this->real = 0;
    //     this->imag = 0;
    // }

    // Complex(int real, int imag){
    //     this->real = real;
    //     this->imag = imag;
    // }

    Complex(int r = 0, int i = 0) : real(r), imag(i) {};

    Complex operator+(const Complex &obj)
    {
        Complex result;
        result.real = this->real + obj.real;
        result.imag = this->imag + obj.imag;
        return result;
    }

    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    Complex c1(2, 4);
    Complex c2(5, 5);

    Complex c3 = c1 + c2;
    c3.display();
}