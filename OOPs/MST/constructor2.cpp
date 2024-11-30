#include <iostream>

using namespace std;


class Example {
    int a;
    public:
    Example(int j) {
        a = j;
    }
    int geta() {
        return a;
    }
};

int main() {
    Example e1 = 5;
    cout<<e1.geta();


    return 0;
}

// class Example {
//     int a,b;
//     public:
//     Example(int x = 0, int y = 0) : a(x), b(y) {}
//     void display();
// };



// void Example :: display(){
//     cout<<a;
//     cout<<endl<<b;
// }

// int main() {
//     Example e1(2,3);
//     Example e2 = Example(10,4);
//     e1.display();
//     e2.display();

//     return 0;
// }





// class Example {
//     int a;
//     public:
//     Example();
//     void display();
// };

// Example :: Example() {
//     a= 0;
// }

// void Example :: display() {
//     cout<<a;
// }

// int main() {
//     Example e1;
//     Example e2 = Example();


//     return 0;

// }
