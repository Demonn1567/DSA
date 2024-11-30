#include <iostream>

using namespace std;

class Time {
    int hrs, mins;

    public:

    void operator=(int);

    void display();
};


void Time :: operator=(int t) {
    hrs = t/60;
    mins = t%60;
}

void Time :: display() {
    cout<<hrs<<" "<<mins<<endl;
}

int main() {
    Time t1;
    int duration;
    cout<<"Enter the duration in minutues"<<endl;
    cin>>duration;

    t1 = duration;

    t1.display();

}
