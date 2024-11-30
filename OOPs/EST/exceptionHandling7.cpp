#include <iostream>

using namespace std;

void handler(int test) {
    try {
        if(test) {
            throw test;
        }
        else {
            throw "zero";
        }
    }
    catch(int i) {
        cout<<i;
    }
    catch(...) {
        cout<<"Caught"<<endl;
    }


}

int main() {
    handler(1);
    handler(2);
    handler(0);

    return 0;
}
