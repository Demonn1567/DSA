#include <iostream>

using namespace std;

class Car { 
    public:
    string model;
    int price;
    string color;

    /* void say(string a) { //function member
        model = a;
    } */

   void setModel(string m) {
    model = m;
   }

   void getModel() {
    cout<<"Model : "<<model<<endl;
   } 

   void setPrice(int p) {
    price = p;
   }

   void getPrice() {
    cout<<"Price : "<<price<<endl;
   }

    void setColor(string c) {
    color = c;
   }

   void getColor() {
    cout<<"Color : "<<color<<endl;
   }

   int show(int);

};

int Car ::show(int x) { //creating a function outside the class using scope resolution operator. (::) , so this become a class member

}



int main() {
    Car* c1;
    c1 = new Car();
    /* c1->model  = "BMWS5";
    c1->price = 50000000;
    c1->color = "Red";

    c1->say("Audi"); */
    c1->setModel("BMWs5");
    c1->setPrice(50000000);
    c1->setColor("Grey");

    c1->getModel();
    c1->getPrice();
    c1->getColor();


   /*  cout<<c1->model<<" ";
    cout<<c1->price<<" ";
    cout<<c1->color<<" "; */

    

    return 0;
}









/* #include <iostream>

using namespace std;

// Classes and Objects
// Class is a blueprint for objects and also known as Factory of Objects
// Syntax to create class

class Student {
    public:
    string name;
    int age;
    string city;
};

// Objects are Instance of Class

int main() {
    // Create Object

    Student* ptr;
    ptr = new Student();

    ptr->name = "Rahul";
    ptr->age = 19;
    ptr->city = "Delhi";  

    cout << ptr->name;

    return 0;
}
 */


