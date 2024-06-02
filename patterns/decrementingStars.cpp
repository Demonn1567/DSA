/* * * * * * 
* * * * 
* * * 
* * 
*  */
#include <iostream>

using namespace std;

void print(int n) {
    for(int i=0;i<n;i++) {
        for(int j=n;j>i;j--) {
            cout<<"* ";
        }
        cout<<endl;
    }
}



int main() {
    int n;
    cout<<"Enter the number of rows";
    cin>>n;
    print(n);
    return 0;
}