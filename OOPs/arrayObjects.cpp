#include <iostream>

using namespace std;

class Student {
    string name;
    int age;

    public:
    void getData();
    void setData();
};

void Student ::getData() {
    cout<<"Name : "<<name<<"\tAge : "<<age<<endl;
}

void Student::setData() {
    cin>>name>>age;
}

int main() {
    Student s[3];

    for(int i =0;i<3;i++) {
        cout<<"Enter details of student "<<i+1;
        s[i].setData();
        cout<<endl;
    }
    for(int i =0;i<3;i++) {
        cout<<"Details of student"<<i+1;
        s[i].getData();
        cout<<endl;
    }

    return 0;
}