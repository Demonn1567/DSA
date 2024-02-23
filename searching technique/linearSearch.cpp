#include <iostream>

using namespace std;

bool linearSearch(int arr[], int size, int target) {
    for(int i=0;i<size;i++) {
        if(arr[i] == target) {
            return true;
        }
        
    }
}

int main() {
    int arr[] = {1,3,54,2,4,35,1,41,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 419;
    int x = linearSearch(arr,size,target);
    cout<<x;
    return 0;
}