#include <iostream>

using namespace std;

class Number {
    int value;
    public :
    Number(int val = 0) {
        value = val;
    }
    void setVal(int val) {
        value =val;
    }
    void display() {
        cout<<value<<" ";
    }

    Number add(Number ob1) {
        Number result;
        result.value = this->value + ob1.value;
        return result;
    }

};


int main() {
    Number n1(10), n2(20);

    Number n3 = n1.add(n2);
    n3.display();

    return 0;
}
