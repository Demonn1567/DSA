#include <cmath>
#include <iostream>

using namespace std;

class base1 {
    protected :
    int x;
    public:
    void showx() {
        cout<<x<<endl;
    }
};

class base2 {
    protected:
    int y;
    public:
    void showy(){
        cout<<y<<endl;
    }
};

class Derived : public base1, public base2 {
    public:
    void set(int i, int j) {
        x = i;
        y = j;
    }
};

int main() {
    Derived d1;
    d1.set(2, 4);
    d1.showx();
    d1.showy();

    return 0;
}
