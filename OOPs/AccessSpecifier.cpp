#include <iostream>

using namespace std;

class Student { 
    string name;
    int scores[5];

    public:
    Student(string n, int s[5]) {
        name = n;
        for(int i =0;i<5;i++) {
            scores[i] = s[i];
        }
    }
    void displayDetails() {
        cout<<"Name : "<<name<<endl;
        for(int i =0;i<5;i++) {
            cout<<scores[i]<<" ";
        }
    }
};


int main() {
    int scores[] = {41,2,4,5,7};

    Student s1("A", scores);
    s1.displayDetails();


    return 0;
}