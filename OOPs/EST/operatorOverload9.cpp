#include <iostream>

using namespace std;

class Distance {
    int feet;
    int inches;
    public:
    Distance();
    Distance(int, int);

    void displayDistance();

    Distance operator-();

};

Distance :: Distance() {
    feet= 0;
    inches = 0;
}

Distance :: Distance(int x, int y) {
    feet =x;
    inches = y;
}

void Distance :: displayDistance(){
    cout<<feet<<" "<<inches<<endl;
}

Distance Distance ::  operator-() {
    feet = -feet;
    inches = -inches;
    return Distance(feet, inches);
}

int main() {
    Distance d1(11,10), d2(-5,10);
    -d1;
    -d2;
    d1.displayDistance();
    d2.displayDistance();
}
