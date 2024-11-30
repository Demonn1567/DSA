#include <iostream>

using namespace std;

void handler(int test) {
    try {
        if(test) {
            throw test;
        }
        else {
            throw "Value is zero";
        }
    }
    catch(int i) {
        cout<<"Caught i : "<<i<<endl;
    }
    catch(const char* s) {
        cout<<s<<endl;
    }
}

int main() {
    handler(1);
    handler(2);
    handler(0);

    return 0;
}
