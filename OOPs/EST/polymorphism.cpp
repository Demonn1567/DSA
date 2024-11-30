#include <iostream>

using namespace std;

class Vehicle {
    public :
    virtual void startEngine() = 0; //pure virutal function
};

class Car : public Vehicle {
    public :
    void startEngine() override {
        cout<< "Car engine started";
    }
};

class Bike : public Vehicle {
    public :
    void startEngine() override {
        cout<<"Bike Engine Started";
    }
};

int main() {
    Bike* b1 = new Bike();
    b1->startEngine();

    return 0;

}
