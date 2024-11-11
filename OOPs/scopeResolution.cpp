#include <iostream>

using namespace std;

class Base {
    private:
    int id;
    int marks;

    public: 
    Base(int i, int m) {
        id = i;
        marks = m;
    }

    void display();
};

void Base::display() {
    cout<<id<<" "<<marks<<endl;

}

int main() {
    Base b1(1,55);
    Base b2(2, 60);

    b1.display();
    b2.display();

    return 0;
}

