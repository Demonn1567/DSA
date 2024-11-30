#include <iostream>

using namespace std;

class Student {
    private:
    string name;
    int roll;
    int marks;

    public:
    void setStudentData(string n, int r, int m) {
        name = n;
        roll = r;
        marks = m;
    }
    void getStudentData() {
        cout<<name<<" "<<roll<<" "<<marks<<endl;
    }
};

int main() {
    Student arr[3];
    string name;
    int roll;
    int marks;
    for(int i =0;i<3;i++) {
        cout<<"Enter name , rollno, and marks of the student";
        cin>>name>>roll>>marks;
        arr[i].setStudentData(name, roll, marks);
    }

    for(int i =0;i<3;i++) {
        arr[i].getStudentData();
    }
}