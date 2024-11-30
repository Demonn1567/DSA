#include <iostream>

using namespace std;


class Distance {
    int feet;
    int inches;
    

    public:
    Distance(int f =0, int i = 0) {
        feet = f;
        inches = i;
    }
    void display() {
        cout<<feet<<" "<<inches<<endl;
    }

    Distance operator-() {
        feet = -feet;
        inches = -inches;
        return *this; // or return Distance(feet,inches)
    }

    bool operator <(Distance& d) {
        if(feet<d.feet) {
            return true;
        }
        return false;
    }
    
};

int main() {
    Distance d1(5,10);
    Distance d2(2,4);

    Distance d3 = -d1;
    //d3.display();

    bool x = d2<d1;
    cout<<x<<endl;

    return 0;
}