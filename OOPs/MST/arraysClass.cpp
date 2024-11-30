#include <iostream>

using namespace std;


class Player {
    string name;
    int scores[5];
    public :
    Player(string n, int s[5]) {
        name = n;
        for(int i=0;i<5;i++) {
            scores[i] = s[i];
        }
    }

    void displayDetails() {
        cout<<"Name : "<<name<<endl<<" Scores : ";
        for(int i =0;i<5;i++) {
            cout<<scores[i]<<" ";
        }
    }
};

int main() {
    int scores[] = {43,21,6,45,23};
    Player p1("Raj", scores);
    p1.displayDetails();


    return 0;
}
