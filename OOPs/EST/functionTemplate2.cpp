#include <iostream>

using namespace std;

template <typename T>
void swap_val(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}
int main() {
    int x = 4, y = 8;
    cout<<x<<" "<<y<<endl;

    swap_val(x,y);
    cout<<x<<" "<<y<<endl;


}
