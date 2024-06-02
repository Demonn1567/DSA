/* 1 2 3 4 5 
1 2 3 4 
1 2 3 
1 2 
1 */
#include <iostream>

using namespace std;

void print(int n) {
    for(int i=n;i>0;i--) {
        for(int j=1;j<=i;j++) {
            cout<<j<<" ";
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