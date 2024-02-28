#include <iostream>

using namespace std;

void Heapify(int i, int arr[], int size) {
    int li = 2*i+1;
    int ri = 2*i+2;
    int largest = i;
    if(li<size&&arr[li]>arr[largest]) {
        largest = li;
    }
    if(ri<size&&arr[ri]>arr[largest]) {
        largest = ri;
    }
    if(largest!=i) {
        swap(arr[i],arr[largest]);
        Heapify(largest, arr, size);
    }
}

int main() {
    int arr[] = {11,4,7,23,3,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = (size/2)-1;i>=0;i--) {
        Heapify(i,arr,size);
    }
    for(int i=size-1;i>=0;i--) {
        swap(arr[0],arr[i]);
        Heapify(0, arr, i);
    }
    for(auto i:arr) {
        cout<<i<<" ";
    }
    return 0;
}