//lab 5 assignment
#include <iostream>

using namespace std;


//q1
/* class Base {
    public:
    int st;
    int ft;

    Base() {
        cout<<"Base Constructor"<<endl;
    }

    void set_val(int x, int y) {
        st= x;
        ft = y;
    }

    void get_val() {
        cout<<st<<" "<<ft<<endl;
        cout<<"getting value from base class"<<endl;
    }
};

class Derived : public Base {
    public:
    int dt;

    Derived() {
        cout<<"Derived Constructor"<<endl;
    }

    void set_val(int a, int b, int c) {
        st = a;
        ft = b;
        dt = c;
    }

    void get_val() {
        cout<<st<<" "<<ft<<" "<<dt<<endl;
        cout<<"Getting value from derived class"<<endl;
    }

};

int main() {
    Base b1;
    b1.set_val(1,2);
    b1.get_val();

    Derived d1;
    d1.set_val(3,4,5);
    d1.get_val();


    

    return 0;
} */

/* //q2
class Base {
    protected:
    int a;
    public:
    Base() {
        cout<<"Base Constructor"<<endl;
    }

    void set_val(int x) {
        a= x;
        cout<<"Setting value in base class"<<endl;
    }

    void get_val() {
        cout<<a<<endl;
        cout<<"getting value from base class"<<endl;
    }
};

class Derived : protected Base {
    public:
    void get_val() {
        cout<<a<<endl;
        cout<<"getting value from derived class"<<endl;
    }

    void set_val(int x) {
        a= x;
        cout<<"Setting value in derived class"<<endl;
    }

};

int main() {
    Base b1;
    b1.set_val(5);
    b1.get_val();

    Derived d1;
    d1.set_val(7);
    d1.get_val();
} */


class Base {
public:
    int publicMember = 1;
protected:
    int protectedMember = 2;
private:
    int privateMember = 3;
};

class Derived : private Base {
public:
    void display() {
        cout << "Public Member: " << publicMember << endl;       
        cout << "Protected Member: " << protectedMember << endl; 
        // cout << "Private Member: " << privateMember << endl;  Not accessible
    }
};

int main() {
    Derived d1;

    d1.display();
    //cout<<d1.publicMember; also not accessible with protected inheritance
    //cout<<d1.protectedMember;  This is not accessible as the member is defined as protected
    return 0;
}

