//basic idea is to keep compairing the adjacent elements
#include <iostream>

using namespace std;

void bubbleSort(int arr[], int size) {
    for(int i=0;i<size-1;i++) {
        for(int j=0;j<size-i-1;j++) {
            swap(arr[j+1],arr[j]);
        }
    }
}

int main() {
    int arr[] = {5,4,3,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"The original array is : ";
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    bubbleSort(arr,size);
    cout<<"The sorted array is : ";
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}