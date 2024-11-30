//dynamic construction of objects
#include <iostream>

using namespace std;

class Example {
    char* name;
    int length;
    public:
    Example();
    Example(char*);
    void display();
};

Example :: Example() {
    length = 0;
    name = new char[length+1];
}

Example :: Example(char* e) {
    length = strlen(e);
    name = new char[length+1];
    strcpy(name,e);
}

void Example :: display() {
    cout<<name<<endl;
}

int main() {
    char* a = "Hi & hello";
    Example e1(a);
    Example e2("Welcome");
    Example e3("to the world");
    e1.display();
    e2.display();
    e3.display();

    return 0;
}
