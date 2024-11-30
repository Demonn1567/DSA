#include <cmath>
#include <iostream>

using namespace std;

class Shape {
    public:
    virtual void show() {
        cout<<"shape"<<endl;
    }
};

class Square : public Shape {
    void show() {
        cout<<"Square"<<endl;
    }
};

class Rectangle : public Shape {
    void show() {
        cout<<"Rectangle"<<endl;
    }
};

int main() {
    Shape* s1 = new Shape();
    s1->show();

    s1 = new Square();
    s1->show();

    s1 = new Rectangle();
    s1->show();
    return 0;
}
