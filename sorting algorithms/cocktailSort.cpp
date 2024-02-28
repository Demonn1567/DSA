#include <iostream>

using namespace std;

void cocktailSort(int arr[], int size) {
    bool isSwap = true;
    int beg = 0;
    while(isSwap) {
        isSwap = false;
        for(int i=0;i<size-1;i++) { 
            if(arr[i]>arr[i+1]) {
                swap(arr[i],arr[i+1]);
                isSwap = true;
            }
        }
        isSwap = false;
        size--;
        for(int i = size-2;i>=beg;i--) {
            if(arr[i]>arr[i+1]) {
                swap(arr[i],arr[i+1]);
                isSwap = true;
            }
        }
        beg++;
    }
}


int main() {
    int arr[] = {7,3,0,17,3,2,7,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    cocktailSort(arr, size);
    for(auto i : arr) {
        cout<<i<<" ";
    }
    return 0;
}