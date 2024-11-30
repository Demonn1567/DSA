#include <iostream>

using namespace std;

class Base {
    public :
    Base() {
        cout<<"B const"<<endl;
    }
    ~Base() {
        cout<<"B destr"<<endl;
    }
};

class Derived : public Base {
    public :
    Derived() {
        cout<<"D const"<<endl;
    }
    ~Derived() {
        cout<<"D destr"<<endl;
    }

};

int main() {
    Derived obj;
    Base* ptr = &obj;
    delete ptr;
    return 0;
}
