#include <iostream>

using namespace std;

class Temp {
    int a;
    public:
    Temp(int);

    void display() {
        cout<<a;
    }
};
Temp :: Temp(int b) {
    a=b;
}


int main() {
    Temp t1(5);
    t1.display();


    return 0;
}
