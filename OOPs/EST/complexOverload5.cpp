#include <iostream>

using namespace std;

class Loc {
    int longitude, latitude;

    public :
    Loc() {
        longitude = 0;
        latitude = 0;
    }

    Loc(int lo, int la) {
        longitude = lo;
        latitude = la;
    }

    void show() {
        cout<<longitude<<" "<<latitude<<endl;
    }

    // Loc operator+(Loc&);
    Loc operator-(Loc&);
    Loc operator=(Loc&);
    Loc operator++();
    Loc operator()(int, int);

    friend Loc operator+(Loc ,Loc);

};

// Loc Loc :: operator+(Loc& l1) {
//     return Loc(l1.longitude + longitude, l1.latitude + latitude);
// }

Loc operator+(Loc l1, Loc l2)  {
    return Loc(l1.longitude + l2.longitude, l1.latitude + l2.latitude);
}

Loc Loc :: operator()(int i, int j) {
    longitude = i;
    latitude = j;

    return *this;
}

Loc Loc :: operator-(Loc& l2) {
    return Loc(l2.longitude - longitude, l2.latitude- latitude);
}

Loc Loc :: operator=(Loc& l3) {
    longitude = l3.longitude;
    latitude = l3.latitude;

    return *this;
}

Loc Loc :: operator++() {
    return Loc(++longitude, ++latitude);
}

int main() {
    Loc l1(3,4), l2(1,2);

    Loc l3 = l1+l2;

    l1(2,5);

    //Loc l4 = ++l1;

    l1.show();


    return 0;
}
