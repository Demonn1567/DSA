#include <iostream>

using namespace std;

template <typename T =int>

class Temp {
    T val;
    public:
    Temp(T v) : val(v) {}
    Temp() {}

    void display() {
        cout<<val<<endl;
    }
    Temp operator+(Temp);
};

template <typename T>

Temp<T> Temp<T> :: operator+(Temp<T> t){
    Temp<T> a;
    a.val = val + t.val;
    return a;
}

int main() {
    Temp<int> t1(4);
    Temp<int> t2(3);
    Temp<int> t3 = t1 + t2;
    t3.display();

    return 0;
}
