#include <iostream>

using namespace std;

class Number {
    int a ,b;
    public:
    Number(int num, int num2) {
        a = num;
        b = num2;
    }
    Number(){
        a = 0;
        b = 0;
    }
    Number (Number& obj) {
        cout<<"Copy constructor called"<<endl;
        a = obj.a;
        b = obj.b;
    }

    void display() {
        cout<<a<<endl;
        cout<<b<<endl;
    }
};

int main() {
    Number x,y,z(45,20);
    x = z;
    x.display();
    y.display();
    z.display();
    Number z1(z);
    z1.display();

    return 0;
}
