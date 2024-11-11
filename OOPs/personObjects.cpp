//name, age, money
#include <iostream>

using namespace std;

class Person {
    public:
    int id;
    string name;
    int age;
    int money;

    //Constructor is a function without a return type, with a name same as that of the class.
    //No need to call the constructor, its gets called itself everytime you make an object.
    //Constructor is responsible for object creation and data member initialization
    //Calls for each objects
    //If no constructor is present, compiler provides default constructor
    //It allocates memory for objects
    //Another way to define a constructor
    /* int n1,n2,n3;
    Text():n1(3),n2(4),n3(6); */

    //Multiple constructors can be different as well, but they cannot be completely same.
    //Function Signature has to be different.
    //Function Signature differs in three ways : 
    //1. Number of parameters.
    //2. Type of parameters.
    //3. Sequence of parameters.

    //const keyword used for variables , doesnt allow to change value of variables
    //data members in class defined as const can only be initalized by constructor.


    //STATIC DATA MEMBERS : only one copy of a variable which is shared by all obecjts of class.
    //static int n;
    


    Person(int i, string n, int a, int m) {
        id =i;
        name  = n;
        age = a;
        money = m;
    }

    //Destructor - used when objects is destroyed.
    //When the whole code is run, the program terminates and default constructor is called.
    //Name of destructor = tilde character(~) followed by class_name
    //Deallocates memory, destroys objects, accept no arguments.


    /* void setDetails(int i, string n, int a, int m) {
        id = i;
        name = n;
        age = a;
        money = m;
    } */

   //objects can be passed as function parameters (values that functions receive.)
   //they are passed in a similar way as variable to a function.

   /* return_type function_name(class_name object_name) {
    return object_name;
     } */




    void getDetails() {
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"Money : "<<money<<endl;
    }

    void addMoney(int m) {
        money+=m;
    }

    void withdrawMoney(int m) {
        if(money < 1000) {
            cout<<"Insufficient Funds.";
        }
        else if(money-m <1000) {
            cout<<"Minimum balance has to be 1000, Kindly maintain that";
        }
        else {
            money-=m;
        }

        
    }

    void transfer(Person* p, int amount) {
        withdrawMoney(amount);

        p->addMoney(amount);
    }

};

int main() {
    Person* p1;
    p1 = new Person(1, "Amit", 27, 8000);
    
    //p1->setDetails(1, "Amit", 27, 8000);

    Person* p2;
    p2 = new Person(2, "Raj", 29, 10000);
    //p2->setDetails(2, "Raj", 29, 10000);

    p1->transfer(p2, 1000);
    p1->getDetails();
    p2->getDetails();
    //p1->getDetails();

    //p1->addMoney(5000);
    //p1->getDetails();

    //p1->withdrawMoney(13000);
    //p1->getDetails();

    return 0;
}