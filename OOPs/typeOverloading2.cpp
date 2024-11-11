#include <iostream>
using namespace std;

class Cartesian; 

class Polar {
    int val1;
    int val2;

    public:
    Polar() {}
    Polar(int v1, int v2) {
        val1 = v1;
        val2 = v2;
    }

    void display() {
        cout << val1 << " " << val2 << endl;
    }

    operator Cartesian();
};

class Cartesian {
    public:
    int v1;
    int v2;

    Cartesian() {}
    
    void show() {
        cout << v1 << " " << v2 << endl;
    }
};

Polar::operator Cartesian() {
    Cartesian temp;
    temp.v1 = val1;
    temp.v2 = val2;

    return temp;
}

int main() {
    Polar p(2, 5);
    Cartesian c = p;  
    c.show();

    return 0;
}
