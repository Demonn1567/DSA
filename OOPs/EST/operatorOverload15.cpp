#include <iostream>

using namespace std;

class Temp {
    public:
    int i;
    Temp(int a) {
        i = a;
    }

    Temp* operator->() {
        return this;
    }

};

int main() {
    Temp obj(2);
    cout<<obj->i;
}
