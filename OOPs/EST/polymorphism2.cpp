#include <iostream>
using namespace std;

class Vehicle {
public:
    void startEngine() { // Non-virtual function
        cout << "Vehicle engine started" << endl;
    }
};

class Car : public Vehicle {
public:
    void startEngine() { // This hides the parent class's method
        cout << "Car engine started" << endl;
    }
};

class Bike : public Vehicle {
public:
    void startEngine() { // This hides the parent class's method
        cout << "Bike engine started" << endl;
    }
};

int main() {
    Vehicle v1;
    Car c1;
    Bike b1;

    Vehicle* vPtr;

    vPtr = &v1;
    vPtr->startEngine(); // Calls Vehicle's startEngine() (compile-time decision)

    vPtr = &c1;
    vPtr->startEngine(); // Still calls Vehicle's startEngine() (early binding)

    vPtr = &b1;
    vPtr->startEngine(); // Still calls Vehicle's startEngine() (early binding)

    return 0;
}
