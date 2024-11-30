#include <iostream>

using namespace std;

class Temp {
    int a;
    static int count;
    public :
    Temp(int b) {
        a = b;
        count++;
    }
    static int getCount(){
        return count;
    }
};

int Temp :: count = 0;


int main() {
    Temp t1(2);
    Temp t2(4);

    cout<<Temp::getCount();

    return 0;
}
