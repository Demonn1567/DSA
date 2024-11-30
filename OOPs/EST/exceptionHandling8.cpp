#include <iostream>

using namespace std;

void handler() {
    try {
        throw "Hello";
    }
    catch(const char* e) {
        cout<<"Caught inside function"<<endl;
        throw;
    }
}

int main() {
    try {
        handler();
    }
    catch(const char* e) {
        cout<<"Caught inside main";
        cout<<e;
    }

    return 0;
}
