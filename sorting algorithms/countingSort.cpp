#include <iostream>

using namespace std;

void countingSort(int arr[], int size) {
    int max = arr[0];
    for(int i=1;i<size;i++) {
        if(arr[i]>max) {
            max = arr[i];
        }
    }
    int count[max+1] = {0};
    for(int i=0;i<size;i++) {
        count[arr[i]]++;
    }
    int size1 = sizeof(count)/sizeof(count[0]);
    for(int i=1;i<size1;i++) {
        count[i]+=count[i-1];
    }
    int output[size] = {0};
    for(int i = size-1;i>=0;i--) {
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    for(int i=0;i<size;i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[] = {2,5,3,0,2,3,0,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    countingSort(arr,size);
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}