#include <iostream>

using namespace std;

class C2; //forward declaration
class C1{
    int val;
    public :
    void indata(int a) {
        val  =a;
    }
    void display() {
        cout<<val<<endl;
    }
    friend void exchange(C1&, C2&);
};
class C2{
    int val2;
    public :
    void indata(int a) {
        val2  =a;
    }
    void display() {
        cout<<val2<<endl;
    }
    friend void exchange(C1&, C2&);
};

void exchange(C1& x, C2& y) {
    int temp = x.val;
    x.val = y.val2;
    y.val2 = temp;
}


int main() {
    C1 a;
    C2 b;
    a.indata(4);
    b.indata(6);
    exchange(a,b);

    a.display();


    return 0;
}
