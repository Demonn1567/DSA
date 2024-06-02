#include <iostream>

using namespace std;

void reverseArray(int arr[], int start, int end) {
    if(start < end) {
        swap(arr[start], arr[end]);
        reverseArray(arr, start+1, end-1);
    } 
}

int main() {
    int arr[] = {1,3,6,7,3,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    reverseArray(arr,0,size-1);
    for(auto i : arr) {
        cout<<i<<" ";
    }
    return 0;
}