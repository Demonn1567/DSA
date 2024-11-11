//friend function implementation by implementing the sum for complex numbers
#include <iostream>

using namespace std;

class Complex {
    int a;
    int b;

    public:
    void setData(int i, int j) {
        a = i;
        b = j;
    }
    void getData() {
        cout<<"The Complex Number is : "<<a<<"+i"<<b<<endl;
    }

    friend Complex sumComplex(Complex o1, Complex o2);

};

Complex sumComplex(Complex o1, Complex o2) {
    Complex o3;
    o3.setData(o1.a+o2.a, o1.b+o2.b);

    return o3;
}

int main() {
    Complex o1,o2,o3;

    o1.setData(1,4);
    o2.setData(2,3);

    o3 = sumComplex(o1,o2);
    o3.getData();

    return 0;
}