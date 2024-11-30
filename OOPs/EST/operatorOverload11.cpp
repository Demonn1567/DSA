#include <iostream>

using namespace std;

class Loc {
    int latitude, longitude;
    public:
    Loc(int la, int lo) {
        latitude = la;
        longitude = lo;
    }
    Loc() {}

    void display() {
        cout<<latitude<<" "<<longitude<<endl;
    }
    friend Loc operator+(Loc, Loc);

};

Loc operator+(Loc op1, Loc op2) {
    Loc temp;
    temp.latitude = op1.latitude + op2.latitude;
    temp.longitude = op1.longitude + op2.longitude;
    return temp;
}

int main() {
    Loc l1(2,5), l2(3,4);
    Loc l3 = l1+l2;
    l3.display();

    return 0;
}
