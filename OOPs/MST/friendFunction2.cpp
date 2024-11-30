//friend functions as a member function of another class
#include <iostream>

using namespace std;

class Complex; //forward declaration

class Calculator {

    public:
    Complex sumComplexNum(Complex o1, Complex o2);
    
};

class Complex{
    int a;
    int b;

    friend Complex Calculator :: sumComplexNum(Complex o1, Complex o2);

    public:
    void setData(int i, int j) {
        a = i;
        b = j;
    }

    void printNum() {
        cout<<"Complex Number is : "<<a<<" + "<<b<<"i"<<endl;
    }
};

Complex Calculator :: sumComplexNum(Complex o1, Complex o2) {
    Complex o3;
    o3.a = o1.a + o2.a;
    o3.b = o1.b + o2.b;
    return o3;
}

int main() {
    Complex o1,o2, o3;
    Calculator calc;
    o1.setData(1,4);
    o2.setData(2,3);

    o3 = calc.sumComplexNum(o1,o2);
    o3.printNum();

    return 0;
}