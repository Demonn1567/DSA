#include <iostream>

using namespace std;

template <typename t1, typename t2>
class Pair {
    t1 first;
    t2 second;
    public:
    Pair(t1 a, t2 b) : first(a), second(b) {}

    void display() {
        cout<<first<<" "<<second<<endl;
    }
};

int main() {
    Pair<int,double> p1(2,5.9);
    p1.display();

    Pair<string, int> p2("Raj", 49);
    p2.display();

    return 0;
}
