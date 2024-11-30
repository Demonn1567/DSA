//friend class
#include <iostream>

using namespace std;

class Complex;
class Calculator {
    public:
    Complex sumComplex(Complex,Complex);
};

class Complex {
    int a,b;
    friend class Calculator;
    public:
    void setVal(int n1, int n2) {
        a = n1;
        b = n2;
    }
    void printNum() {
        cout<<a<<" + "<<b<<"i";
    }

};

Complex Calculator :: sumComplex(Complex c1, Complex c2) {
    Complex c3;
    c3.a = c1.a + c2.a;
    c3.b = c1.b + c2.b;
    return c3;
}

int main() {
    Complex c1,c2,c3;
    c1.setVal(2, 5);
    c2.setVal(3, 5);

    Calculator o1;
    c3 = o1.sumComplex(c1, c2);
    c3.printNum();


    return 0;
}


// //friend functions as a member function of another clas
// #include <iostream>

// using namespace std;

// class Complex;
// class Calculator {
//     public:
//     Complex sumComplex(Complex,Complex);
// };

// class Complex {
//     int a,b;
//     friend Complex Calculator :: sumComplex(Complex, Complex);
//     public:
//     void setVal(int n1, int n2) {
//         a = n1;
//         b = n2;
//     }
//     void printNum() {
//         cout<<a<<" + "<<b<<"i";
//     }

// };

// Complex Calculator :: sumComplex(Complex c1, Complex c2) {
//     Complex c3;
//     c3.a = c1.a + c2.a;
//     c3.b = c1.b + c2.b;
//     return c3;
// }

// int main() {
//     Complex c1,c2,c3;
//     c1.setVal(2, 5);
//     c2.setVal(3, 5);

//     Calculator o1;
//     c3 = o1.sumComplex(c1, c2);
//     c3.printNum();


//     return 0;
// }
