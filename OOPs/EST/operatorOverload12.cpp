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
    Temp ob(1,2,3);
    cout<<ob[1];
    ob[1] = 5;
    cout<<endl<<ob[1];

    return 0;
}
