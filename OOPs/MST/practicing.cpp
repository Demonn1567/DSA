#include <iostream>

using namespace std;

class Car {
    public:
    int maxSpeed;
    int model;

    Car(int s, int m);

    Car(Car& c) {
        maxSpeed = c.maxSpeed;
        model = c.model;
    }
     
    ~Car() { //destructor
        cout<<"Destructed";
    }

    void increasemaxSpeed();
};

Car :: Car(int s, int m) {

    maxSpeed = s;
    model  = m;
}

void Car::increasemaxSpeed() { //defining a member function outside the class using scope resolution operator(::)
    maxSpeed+=50;
}

int main() {
    Car c1(350, 2024);

    cout<<c1.maxSpeed;

    cout<<endl;

    //c1.increasemaxSpeed();
    //cout<<c1.maxSpeed;

    Car* c2 = new Car(c1);
    cout<<endl<<c2->maxSpeed;

    return 0;

};