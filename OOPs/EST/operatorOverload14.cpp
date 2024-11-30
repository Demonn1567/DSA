#include <cmath>
#include <iostream>

using namespace std;

class Test {
    int value;
    public:
    Test(int val) : value(val) {}

    Test operator,(Test& obj) {
        cout<<"Comma operator called : ";
        cout<<this->value<<" "<<obj.value<<endl;

        return obj;
    }

    int getValue() {
        return value;
    }
};

int main() {
    Test t1(10), t2(15), t3(5);

    Test result = (t1,t2,t3);

    cout<<result.getValue();
}
