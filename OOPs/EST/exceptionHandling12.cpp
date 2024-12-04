#include <iostream>

using namespace std;

int main() {
    int a,b;
    cout<<"Enter two values"<<endl;
    cin>>a>>b;
    int x = a-b;

    try{
        if(x!=0) {
            cout<<a/x;
        }
        else {
            throw x;
        }
    }
    catch(int i) {
        cout<<"Caught i : "<<i;
    }

    return 0;
}
