#include <iostream>

using namespace std;


class Num {
    int a,b;
    public:
    void setVal(int n1, int n2) {
        a = n1;
        b = n2;
    }
    friend class Min;
};

class Min {
    public:
    int minVal(Num&);
};

int Min :: minVal(Num& n1) {
    return (n1.a < n1.b) ? n1.a : n1.b;
}

int main() {
    Num n1;
    n1.setVal(2, 4);
    Min m;
    cout<<m.minVal(n1);

    return 0;
}
