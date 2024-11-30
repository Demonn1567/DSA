#include <iostream>
using namespace std;

class Test {
    int value;

public:
    Test(int val) : value(val) {}

    // Overloading the comma operator
    Test operator,(const Test& obj) {
        cout << "Comma operator called: ";
        cout << "this->value = " << this->value << ", obj.value = " << obj.value << endl;

        // Returning the second object (or any appropriate value)
        return obj;
    }

    int getValue() const {
        return value;
    }
};

int main() {
    Test t1(10), t2(20), t3(30);

    // Using the comma operator
    Test result = (t1, t2, t3);

    cout << "Result value: " << result.getValue() << endl;

    return 0;
}
