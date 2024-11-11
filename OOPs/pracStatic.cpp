#include <iostream>

using namespace std;

class Employee {
    int id;
    static int count;

    public:
    Employee() {
        count++;
    }
    void setData(void) {
        cout<<"Enter id of employee : ";
        cin>>id;
    }
    void getData(void) {
        cout<<"Id of employee is : "<<id<<endl;
    }
    void totalEmployees() {
        cout<<"Total number of employees is : "<<count;
    }
};

int Employee :: count = 0; //static variables are defined outside the class


int main() {
    Employee e1,e2;
    e1.setData();
    e1.getData();

    e2.setData();
    e2.getData();

    e1.totalEmployees();
    
    return 0;
}