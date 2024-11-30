#include <iostream>

using namespace std;

class Example {
    int a;
    public:
    Example(int);
    ~Example();
    void display();
};

Example :: Example (int x) {
    a = x;
}
Example ::~Example() {
    cout<<"Object destroyed";
}

void Example :: display() {
    cout<<a;
}

int main() {
    Example e1(5);
    e1.display();
    return 0;
}
