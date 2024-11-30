#include <iostream>

using namespace std;


class MyClass {
    int a,b;
    public:
    void set(int i, int j) {
        a = i;
        b = j;
    }

    friend int summ(MyClass&);

};

int summ(MyClass& x) {
    return x.a + x.b;
}

int main() {
    MyClass m1;
    m1.set(2,3);
    cout<<summ(m1);

    return 0;
}
