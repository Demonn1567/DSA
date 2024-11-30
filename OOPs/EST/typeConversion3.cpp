//class to basic type
#include <iostream>
#include <sys/_types/_int8_t.h>

using namespace std;

class Time {
    int hrs, mins;

    public:
    Time(int h, int m) {
        hrs = h;
        mins = m;
    }

    operator int();

    void display() {
        cout<<hrs<<" "<<mins;
    }
};

Time :: operator int() {
    return(hrs*60 + mins);
}

int main() {
    Time t1(2,4);


    //1st method
    //int duration = t1;

    //2nd method
    int duration = t1.operator int();
    cout<<duration;

    return 0;
}
