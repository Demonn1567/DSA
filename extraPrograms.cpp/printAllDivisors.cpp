#include <iostream>

using namespace std;

void printDivisors(int n) {
    cout<<"The divisors of"<<n<<"are"<<endl;
    for(int i=1;i<=sqrt(n);i++) {
        if(n%i==0) {
            cout<<i<<" ";
            if(i!=n/i) cout<<n/i<<" ";   
        }
        cout<<endl;
    }
}

int main() {
    printDivisors(36);
    return 0;
}