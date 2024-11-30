#include <iostream>
using namespace std;

class Temp {
private:
    float value;

public:
    Temp(float v) {
        value = v;
    }

    void display() {
        cout << "Value: " << value << endl;
    }

    operator float() {
        return value;
    }

};

int main() {
    float num = 5.25;

    Temp obj2 = num;  

    Temp obj1(4.5);

    float t = obj1;
    cout<<t<<endl;

    //obj2.display();

    return 0;
}
