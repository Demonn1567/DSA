#include <iostream>

using namespace std;

class Time {
    int hrs, mins;
    public:
    Time(int);
    void display() {
        cout<<hrs<<" "<<mins<<endl;
    }
};

Time :: Time(int t) {
    hrs = t/60;
    mins = t%60;
}

int main() {
    int t;
    cout<<"Enter duration in mins"<<endl;
    cin>>t;
    Time t1 = t;
    t1.display();

    return 0;
}
