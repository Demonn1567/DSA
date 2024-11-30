//conversion from class type to class type
#include <iostream>

using namespace std;

class Time {
    int hrs, mins;
    public :
    Time(int h, int m) {
        hrs = h;
        mins = m;
    }
    Time(){}

    void display()
    {
        cout<<hrs<<" "<<mins<<endl;
    }

    int getMinutes() {
        return (hrs*60 + mins);
    }
};

class Minute {
    int min;
    public :
    Minute() {
        min = 0;
    }

    void operator=(Time T) {
        min = T.getMinutes();
    }

    void display() {
        cout<<min<<endl;
    }

};


int main() {
    Time t1(2,30);
    t1.display();

    Minute m1;
    m1.display();

    m1 = t1;

    m1.display();
    t1.display();

    return 0;
}
