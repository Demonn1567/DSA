#include <iostream>

using namespace std;

class Complex {
    int a,b;
    public:
    Complex(int x, int y) {
        a = x;
        b = y;
    }
    Complex (int x) {
        a = x;
        b = 0;
    }
    void printNum() {
        cout<<a<<" + "<<b<<"i"<<endl;
    }
};

int main() {
    Complex c1(2,4);
    c1.printNum();
    Complex c2(5);
    c2.printNum();
}
