#include <iostream>

using namespace std;


class Temp {
    int value;

    public:
    Temp(int v) {
        value = v;
    }
    Temp(){}

    void show() {
        cout<<value<<endl;
    }

    void operator++() {
        ++value;
    }

    Temp operator++(int) {
        Temp t = *this;

        value++;

        return t;
    }

};


int main() {
    Temp t1(5);
    t1.show();
    t1++;
    t1.show();

    Temp t2 = t1++;

    t2.show();
    t1.show();

    return 0;
}
