#include <iostream>

using namespace std;

void bubbleSort(int arr[], int size) {
    for(int i=0;i<size-1;i++) {
        for(int j=0;j<size-i-1;j++) {
            if(arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int size) {
    for(int i=0;i<size-1;i++) {
        int min = i;
        for(int j=i+1;j<size;j++) {
            if(arr[j]<arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}


void insertionSort(int arr[], int size) {
    for(int i=0;i<size;i++) {
        int j=i;
        while(j>0 && arr[j-1]>arr[j]) { //OR for(int j=i;j>0 && arr[j-1]>arr[j];j--)
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

int main() {
    int arr[] = {45,3,71,2,9,11,0,3,2,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"The original array is : ";
    for(auto i : arr) {
        cout<<i<<" ";
    }
    insertionSort(arr,size);
    cout<<endl<<"The sorted array is : ";
    for(auto i : arr) {
        cout<<i<<" ";
    }
    return 0;
}