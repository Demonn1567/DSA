#include <iostream>

using namespace std;

class loc {
    int longitude, latitude;
    public:
    loc(int lo, int la) {
        longitude = lo;
        latitude = la;
    }
    loc(){}

    void display() {
        cout<<longitude<<" "<<latitude<<endl;
    }

    loc operator+(loc op1);
    loc operator-(loc op2);
    loc operator=(loc op2);
    loc operator++();
};

loc loc :: operator+(loc op1) {
    loc temp;
    temp.longitude = longitude + op1.longitude;
    temp.latitude = latitude + op1.latitude;

    return temp;
}

loc loc ::operator-(loc op2) {
    loc temp;
    temp.longitude = longitude-op2.longitude;
    temp.latitude = latitude - op2.latitude;
    return temp;
}

loc loc ::operator=(loc op2) {
    longitude = op2.longitude;
    latitude = op2.latitude;

    return *this;
}

loc loc ::operator++() {
    longitude++;
    latitude++;

    return *this;
}

int main() {
    loc l1(2,4), l2(4,5);

    loc l3  = l1+l2;

    ++l3;
    l3.display();
    loc l4 = l3-l1;
    l4.display();
    loc l5 = l4;
    l5.display();


}
