#include <iostream>

using namespace std;

class Parent {
    public:
    int money;
    string car;
    string home;

    void details() {
        cout<<"Money : "<<money<<endl;
        cout<<"Car : "<<car<<endl;
        cout<<"Home : "<<home<<endl;
    }
};

class Child : public Parent {
    
};



int main() {
    Child* c = new Child();

    c->money = 5000;
    c->car = "Mustang";
    c->home  = "Bungalow";

    c->details();

    return 0;
}

