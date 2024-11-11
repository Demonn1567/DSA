#include <iostream>

using namespace std;

class Complex  {
    private:
    float real, img;

    public:
    void setVal(float r, float i) {
        real = r;
        img = i;
    }
    void displayComplex() {
        cout<<"Real part : "<<real<<" "<<"Imaginary part : "<<img<<endl;
    }
    Complex* summ(Complex* A, Complex* B, Complex* C) {
        C->real = A->real + B->real;
        C->img = A->img + B->img;

        return C;
    }
};

int main() {
    Complex* c1 = new Complex();
    Complex* c2 = new Complex();
    Complex* c3 = new Complex();
    Complex* arr[3];
    c1->setVal(1.4,2);
    c2->setVal(3.1, 3);
    c1->displayComplex();
    c2->displayComplex();

    arr[0]->setVal(5.2, 2);
    arr[0]->displayComplex();
    
    c3->summ(c1,c2,c3);
    c3->displayComplex();


    return 0;
}