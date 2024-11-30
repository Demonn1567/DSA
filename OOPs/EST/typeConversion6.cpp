#include <iostream>

using namespace std;

class Time {
    int hrs, mins;
    public:
    void operator=(int);
    void display() {
        cout<<hrs<<" "<<mins<<endl;
    }
};

void Time :: operator=(int t) {
    hrs = t/60;
    mins = t%60;
}

int main() {
    int t;
    cout<<"Enter duration in mins"<<endl;
    cin>>t;
    Time t1;
    //t1 = t;
    t1.operator=(t);
    t1.display();

    return 0;
}
