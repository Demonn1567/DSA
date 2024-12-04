#include <ctime>
#include <iostream>

using namespace std;

template <typename T>

class Box {
    T value;
    public:
    Box(T val) : value(val) {}

    void display() {
        cout<<value<<endl;
    }
    T divideby2();
};
template <typename T>
T Box<T>::divideby2() {
    return value/2;
}

int main() {
    Box<int> b1(5);
    b1.display();

    Box<double> b2(3.14);
    b2.display();
    cout<<b1.divideby2();

    return 0;


}
