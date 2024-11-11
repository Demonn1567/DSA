//program implementing complex numbers and also showing how objects are passed as function arguments
#include <iostream>

using namespace std;

class Complex {
    int a;
    int b;

    public:
    void setData(int v1, int v2) {
        a = v1;
        b = v2;
    }

    void setDataBySum(Complex o1, Complex o2) {
        a = o1.a + o2.a;
        b = o2.b + o1.b;
    }

    void printComplexNumber() {
        cout<<"Complex Number is : "<<a<<"+i"<<b<<endl;
    }

};

int main() {
    Complex o1,o2,o3;
    o1.setData(1,4);
    o2.setData(2,7);
    o3.setDataBySum(o1,o2);
    o3.printComplexNumber();

    return 0;
}