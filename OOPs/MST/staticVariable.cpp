#include <iostream>

using namespace std;

class MyClass {

    public:
    static int x;

    
    void display() {
        int x = 20;
        cout<<"Local x : "<<x<<endl;
        cout<<"Static x : "<<MyClass::x;

    }
};

int MyClass::x = 10;

int main() {
    MyClass obj1;
    //obj1.display();
    cout<<&obj1.x;
    cout<<endl;
    MyClass obj2;
    cout<<&obj2.x;
    cout<<endl;
    obj1.x = 5;
    cout<<obj1.x<<endl;
    cout<<obj2.x;

    

    
    return 0;
}