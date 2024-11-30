#include <iostream>

using namespace std;

class Complex {
    public:
    float real, imag;

    Complex (float r, float i) : real(r), imag(i) {}

    Complex operator+(Complex& c) {
        return Complex(real  +c.real, imag + c.imag);
    }

    void display() {
            cout << real << " + " << imag << "i" << endl;
        }

};

int main() {
    Complex c1(2.2, 4), c2(2, 4.2);
    Complex c3 = c1+c2;
    c3.display();

    return 0;
}
