// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Write C++ code here
   vector<int > v5;
   int m=2,n=3;
    v5.resize(m);

   for(int i=0;i<m;i++) {
    
        v5[i] = 2;
    
   }

   int size = v5.size();
   cout<<size<<endl;
   //int s2 = v5[0].size();
   

    return 0;
}