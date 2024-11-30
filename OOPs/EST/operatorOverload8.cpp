#include <iostream>

using namespace std;


class Temp {
    public:
    int i;

    Temp* operator->() {
        return this;
    }
};

int main(){
    Temp o1;
    o1->i =5;
    cout<<o1->i;
}
