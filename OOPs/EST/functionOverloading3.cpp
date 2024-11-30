#include <iostream>

using namespace std;

double myFunc(double i) {
    return i;
}

float myFunc(float i) {
    return i;
}

int main() {
    cout<<myFunc(10.1);
    //cout<<myFunc(10); //call to myFunc is ambiguous
    return 0;
}
