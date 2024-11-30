#include <iostream>

using namespace std;


class Complex {
    int a,b;
    public:
    void setNumber(int n1, int n2) {
        a = n1;
        b = n2;
    }
    void printNum() {
        cout<<a<<" + "<<b<<"i";
    }
    friend Complex addComplex(Complex, Complex);
};

Complex addComplex(Complex o1, Complex o2) {
    Complex o3;
    o3.a = o1.a + o2.a;
    o3.b = o1.b + o2.b;
    return o3;
}


int main() {
    Complex c1, c2;
    c1.setNumber(1, 4);
    c2.setNumber(5, 8);

    Complex c3 = addComplex(c1, c2);
    c3.printNum();

    return 0;
}
