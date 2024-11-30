#include <iostream>

using namespace std;

class B {

};

class D : public B {

};


int main()
{
    D derived;
    try {
        throw derived;
    }
    catch(B b) {
        cout<<"Caught base class";
    }
    catch(D d) {
        cout<<"catch derived class";
    }

    return 0;
}
