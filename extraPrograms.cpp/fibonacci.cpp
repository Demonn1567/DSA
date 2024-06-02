#include <iostream>

using namespace std;



int main(){
    int n=9;

    if(n==0) {
        cout<<0;
    }

    int first = 0;
    int second = 1;
    int curr;

    for(int i=2;i<=n;i++) {
        curr = first + second;
        first = second;
        second = curr;
        cout<<curr<<" ";
    }

    
    

}