#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if(b==0) {
        return a;
    }
    return gcd(a,b%a);
}

int main() {
    int a = 4, b=8;
    cout<<"GCD of the two numbers is : "<<gcd(a,b);
    return 0;
}