#include <iostream>

using namespace std;

template <typename T>
T add(T a, T b) {
    return a+b;
}

int main() {
    cout<<add(2,5)<<endl;
    cout<<add(2.4,3.2)<<endl;

}
