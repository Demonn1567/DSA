#include <iostream>

using namespace std;

class Enclosing {
    int x;
    public :
    Enclosing(int a) {
        x = a;
    }
    class Nested {
        int y;
        public:
        void nestedFun(Enclosing e) {
            cout<<e.x;
        }
    };
};

int main() {
    Enclosing::Nested n1;
    Enclosing e(5);
    n1.nestedFun(e);

}
