#include <iostream>
#include <cmath>

using namespace std;

class Point{
    int x,y;
    public:
    Point(int a, int b) {
        x = a;
        y = b;
    }
    void displayPoint() {
        cout<<x<<" "<<y<<endl;
    }
    friend int distancePoint(Point &p1, Point& p2);
};

int distancePoint(Point& p1, Point& p2) {
    return (sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2)));
}


int main()  {
    Point p(1,1);
    p.displayPoint();

    Point q(4,6);
    q.displayPoint();

    cout<<distancePoint(p,q);

    return 0;
}
