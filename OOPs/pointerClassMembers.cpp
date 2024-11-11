#include <iostream>

using namespace std;

class Test {
    public:
    int x;

    void display() {
        cout<<x;
    }
};

int main() {
    Test t1, t;

    int Test :: *ptr = &Test::x;

    t1.*ptr = 5;
    t1.display();

    Test* tp = &t;

    tp->*ptr  = 10;
    t.display();




    return 0;
}