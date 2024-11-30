#include <iostream>

using namespace std;


class Distance {
    int feet, inches;

    public :
    Distance();
    Distance(int, int);

    void  displayDistance();

    Distance operator-();

};

Distance :: Distance() {
    feet =0;
    inches = 0;
}

Distance :: Distance(int f, int i) {
    feet = f;
    inches = i;
}

void Distance :: displayDistance() {
    cout<<"Feet : "<<feet<<"  inches : "<<inches<<endl;
}

Distance Distance :: operator-() {
    feet = -feet;
    inches = -inches;
    return Distance(feet, inches);
}

int main() {
    Distance d1(2,4), d2(6,-7);

    -d1;
    d1.displayDistance();

    -d2;
    d2.displayDistance();

    return 0;
}
