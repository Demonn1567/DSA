#include <iostream>

using namespace std;

class Distance {
    int x;
    int y;

    public:
    Distance(int a = 0,int b= 0) {
        x=a;
        y=b;
    }

    Distance operator+(Distance& d) {
        Distance d3;
        d3.x = x + d.x;
        d3.y = y + d.y;

        return d3;
    }

    void display() {
        cout<<x<<" "<<y<<endl;
    }

};


int main() {
    Distance d1(5,10);
    Distance d2(2,4);

    Distance d3 = d1 + d2;

    d3.display();

    return 0;
}