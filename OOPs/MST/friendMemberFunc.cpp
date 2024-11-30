#include <iostream>

using namespace std;

class Base;

class AnotherClass {
    public:
    void memberFunc(Base& obj1);
};

class Base {
    private:
    int private_var;
    protected:
    int protected_var;
    public:
    Base() {
        private_var =10;
        protected_var = 20;
    }

    friend void AnotherClass::memberFunc(Base&);
};

void AnotherClass::memberFunc(Base& obj1 ) {
    cout<<obj1.private_var<<" "<<obj1.protected_var;
}

int main() {
    Base obj1;
    AnotherClass obj2;
    obj2.memberFunc(obj1);

    return 0;
}




