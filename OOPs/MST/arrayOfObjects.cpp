#include <iostream>

using namespace std;

class Employee {
    int id;
    int salary;
    public:
    void setId() {
        salary = 122;
        cout<<"Enter id of employee"<<endl;
        cin>>id;
    }

    void getId() {
        cout<<"Id of the employee is"<<id<<endl;
    }

};

int main() {
    int employees;
    cout<<"Enter number of employees";
    cin>>employees;
    cout<<endl;

    Employee es[employees];
    for(int i =0;i<employees;i++) {
        es[i].setId();
        es[i].getId();
    }

}