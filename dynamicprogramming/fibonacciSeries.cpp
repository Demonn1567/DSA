#include <iostream>
#include <vector>
using namespace std;

int fib(int terms, vector<int> DP) {
    if(terms == 0) return 0;
    if(terms == 1) return 1;

    if(DP[terms]!=-1) {
        return DP[terms];
    }
    DP[terms] = fib(terms-1,DP) + fib(terms-2, DP);

    return DP[terms];

}


int main() {
    vector<int> DP(6,-1);
    int term = fib(4,DP);
    cout<<term;
    return 0;
}
