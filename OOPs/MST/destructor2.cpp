#include <iostream>

using namespace std;

class num {
    static int count;
    public:
    num() {
        count++;
        cout<<"Constructor called"<<count<<endl;
    }
    ~num() {
        cout<<"Destructor called"<<count<<endl;
        count--;
    }
};

int num :: count = 0;

int main() {
    cout<<"Inside main"<<endl;
    cout<<"creating first object n1"<<endl;
    num n1; {
        cout<<"entering block"<<endl;
        cout<<"creating two more objects"<<endl;
        num n2,n3;
        cout<<"exiting block"<<endl;
    }
    cout<<"back to main"<<endl;

    return 0;
}
