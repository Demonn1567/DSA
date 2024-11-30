#include <iostream>

using namespace std;

int main() {
    try {
        try {
            throw 20;
        }
        catch(int n) {
            cout<<"partial"<<endl;
            throw;
        }
    }
    catch(int n) {
        cout<<"remaining"<<endl;
    }


    return 0;
}
