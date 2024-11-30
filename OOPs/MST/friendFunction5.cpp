#include <iostream>

using namespace std;

class Y; //forward declaration
class X {
    int data;
    public:
    void setVal(int val) {
        data = val;
    }
    friend void add(X,Y);
};

class Y {
    int num;
    public:
    void setVal(int val) {
        num = val;
    }
    friend void add(X,Y);
};

void add(X a, Y b) {
    cout<<a.data + b.num;
}

int main() {
    X a;
    Y b;
    a.setVal(4);
    b.setVal(3);

    add(a,b);

    return 0;
}
