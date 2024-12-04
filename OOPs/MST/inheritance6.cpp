#include <iostream>
#include <sys/wait.h>

using namespace std;

class Member {
    char gender[10];
    int age;
    public:
    void get() {
        cin>>gender>>age;
    }
    void display() {
        cout<<gender<<" "<<age<<" ";
    }
};

class Stud : public Member {
    char level[10];
    public:
    void getData() {
        Member :: get();
        cin>>level;
    }
    void disp2() {
        Member::display();
        cout<<level<<" ";
    }
};

class Staff : public Member {
    float salary;
    public:
    void getData() {
        Member :: get();
    cin>>salary;
    }
    void disp3() {
        Member:: display();
        cout<<salary<<endl;
    }

};

int main() {
    Staff s;
    Stud stu;
    stu.getData();
    stu.disp2();
    s.getData();
    s.disp3();


    return 0;
}
