#include <iostream>

using namespace std;

int x = 5;

int main() {
    int x = 10;
    cout<<"Local Variable : "<<x;
    cout<<endl;
    cout<<"Global Variable  :"<<::x;
}