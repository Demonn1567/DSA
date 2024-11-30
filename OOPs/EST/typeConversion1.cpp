//basic to class type using constructors
#include <iostream>

using namespace std;

class Time {
    int hrs, mins;

    public:
    Time(int);

    void display();
};

Time :: Time(int t) {
    hrs = t/60;
    mins =t%60;
}

void Time :: display() {
    cout<<hrs<<" "<<mins<<endl;
}

int main() {
    int duration;
    cout<<"Enter the duration in minutues"<<endl;
    cin>>duration;

    Time t1 = duration;

    t1.display();

}
