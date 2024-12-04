#include <iostream>

using namespace std;

class Shape {
    protected:
    int width;
    int height;
    public:
    void setWidth(int w) {
        width = w;

    }
    void setHeight(int h) {
        height =h;
    }
};

class PaintCost {
    public:
    int getCost(int area) {
        return area*70;
    }
};

class Rectangle : public Shape, public PaintCost {
    public:
    int getArea() {
        return (height*width);
    }
};

int main() {
    Rectangle r1;
    r1.setHeight(5);
    r1.setWidth(4);
    int area = r1.getArea();
    int cost = r1.getCost(area);
    cout<<cost;

    return 0;
}
