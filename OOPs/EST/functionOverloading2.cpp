#include <iostream>

using namespace std;

int myFunc(int i) {
    return i;
}

int myFunc(int i, int j) {
    return i*j;
}

int main() {
    cout<<myFunc(2);
    cout<<" "<<myFunc(2,4);

    return 0;
}
