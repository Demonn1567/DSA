#include <iostream>

using namespace std;


class Emp {
    string name;
    int age;

    public:
    void setData();
    void getData();
};


void Emp :: setData() {
    cin>>name>>age;
}

void Emp::getData() {
    cout<<name<<" "<<age<<endl;
}

int main() {
    Emp e[3];

    for(int i =0;i<3;i++) {
        cout<<"Enter details of student : "<<i+1<<" ";
        e[i].setData();
        cout<<endl;
    }

    for(int i =0;i<3;i++) {
        cout<<"Details of student : "<<i+1;
        e[i].getData();
    }



    return 0;
}
