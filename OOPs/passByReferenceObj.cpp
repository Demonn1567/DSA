#include <iostream>

using namespace std;

class Student {
    private:
    int age;

    public:
    Student(int a) {
        age = a;
    }
    void getAge() {
        cout<<age;

    }

    void update(Student& s1) {
        s1.age+=2;
        cout<<s1.age<<endl;
    }


};

int main() {
    Student s1(3);

    s1.update(s1);

    s1.getAge(); //age 3 changes because the object is passed by reference



}