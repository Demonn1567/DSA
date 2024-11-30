#include <iostream>

using namespace std;

class Time {
    int hrs, mins;
    public:
    Time(int h, int m) {
        hrs = h;
        mins = m;
    }

    operator int();

    void display(){
        cout<<hrs<<" "<<mins;
    }

};

Time :: operator int() {
    return (hrs*60 +mins);
}

int main() {
    Time t1(2,40);
    int duration = t1;
    cout<<duration;

    int duration2 = int(t1);
    cout<<duration2;

    int duration3 = t1.operator int();
    cout<<duration3;
}
