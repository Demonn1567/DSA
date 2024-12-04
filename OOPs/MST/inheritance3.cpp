#include <iostream>

using namespace std;

class Base {
    public:
    void display1() {
        cout<<"base"<<endl;
    }
};

class Derived1 : public Base {
    public:
    void display2() {
        cout<<"Derived1"<<endl;
    }
};

class Derived2 : public Derived1 {
    public:
    void display3() {
        cout<<"Derived2"<<endl;
    }
};

int main(){
    Derived2 d;
    d.display1();
    d.display2();
    d.display3();

    return 0;
}
