#include <iostream>

using namespace std;

class Loc {
    int latitude, longitude;
    public:
    Loc(int la, int lo) {
        latitude = la;
        longitude = lo;
    }
    Loc (){}

    void display() {
        cout<<latitude<<" "<<longitude<<endl;
    }

    Loc operator+(Loc);
    Loc operator()(int, int);
};

Loc Loc ::  operator+(Loc op1) {
    Loc temp;
    temp.latitude = latitude + op1.latitude;
    temp.longitude = longitude + op1.longitude;

    return temp;
}

Loc Loc :: operator()(int i, int j) {
    latitude = i;
    longitude = j;
    return *this;
}

int main() {
    Loc ob1(2,4), ob2(5,2);

    ob1.display();
    ob1(1,2);
    ob1.display();

    return 0;
}
