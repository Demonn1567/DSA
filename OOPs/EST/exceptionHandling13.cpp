#include <iostream>
#include <cstring>
using namespace std;


class Temp {
    public:
    char str[80];
    int a;
    public:
    Temp(char *s, int e) {
        strcpy(str,s);
        a = e;
    }
};

int main() {
    int a;
    try {
    cout<<"Enter a num"<<endl;
    cin>>a;
    if(a<0){
        throw Temp("Not positive", a);
    }
    }
    catch(Temp t) {
        cout<<t.str<<t.a;
    }
}
