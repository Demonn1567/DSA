#include <iostream>

using namespace std;

class Test {
    int val1;
    int val2;

    public:
    Test() {}
    Test(int v1, int v2) {
        val1 = v1;
        val2 = v2;
    }

    void display() {
        cout<<val1<<" "<<val2<<endl;
    }
};


int main() {
    Test obj1(2,4);

    Test obj2 = obj1;

    obj2.display();

    return 0;
}