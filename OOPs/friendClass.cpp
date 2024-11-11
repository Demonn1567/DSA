#include <iostream>

using namespace std;


class Complex; //forward declaration
class Calculator {
    public:
    Complex sumComplex(Complex o1, Complex o2);

};


class Complex {
    int a, b;


    friend class Calculator;

    public:
    void setData(int i, int j) {
        a = i;
        b = j;
    }
    void printData() {
        cout<<"Complex Number is : "<<a<<" + "<<b<<"i"<<endl;
    }
};

Complex Calculator :: sumComplex(Complex o1, Complex o2) {
    Complex o3;
    o3.a = o1.a+ o2.a;
    o3.b = o1.b + o2.b;
    return o3;
}


int main (){
    Complex o1, o2,o3;
    Calculator calc;
    o1.setData(1,4);
    o2.setData(2,3);

    o3 = calc.sumComplex(o1,o2);
    o3.printData();



    return 0;
}






























/* #include <iostream>

using namespace std;

class A {
    private:
    int priv_var;
    protected:
    int prot_var;

    public:
    A() {
        priv_var = 5;
        prot_var = 10;
    }

    friend class F;
};

class F{ 
    public:
    void display(A& t) {
        cout<<t.priv_var<<" "<<t.prot_var;
    }
};

int main() {
    F obj1;
    A obj2;

    obj1.display(obj2);

    return 0;
} */