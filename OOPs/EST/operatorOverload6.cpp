#include <iostream>

using namespace std;


class Temp {
    int a[3];

    public:
    Temp(int i, int j, int k) {
        a[0] = i;
        a[1] = j;
        a[2] = k;
    }
    int &operator[](int i) {
        return a[i];
    }
};


int main() {
    Temp t1(2,3,4);
    //cout<<t1[2];

    t1[1] =  6;
    cout<<t1[1];

    return 0;
}
