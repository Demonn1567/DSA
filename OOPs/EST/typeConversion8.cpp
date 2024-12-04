#include <iostream>

using namespace std;

class Time {
    int hrs, mins;
    public:
    Time(int h, int m) : hrs(h), mins(m){}

    int getMinutes() {
        return (hrs*60 + mins);
    }
};

class Minutes {
    int min;
    public:
    void operator=(Time T) {
        min = T.getMinutes();
    }
    void display() {
        cout<<min;

    }
};

int main() {
    Time t1(2,40);
    Minutes m1;

    m1  = t1;
    m1.display();


    return 0;
}
