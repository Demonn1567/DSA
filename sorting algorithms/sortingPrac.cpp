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
        int min = arr[i];
        int pos = i;
        for(int j=i+1;j<size;j++) {
            if(arr[j]<min) {
                min = arr[j];
                pos = j;
            }
        }
        swap(arr[i],arr[pos]);
    }
}

void insertionSort(int arr[], int size) {
    for(int i=1;i<size;i++) {
        int temp = arr[i];
        for(int j=i;j>0 && arr[j-1]>temp;j--) {
            swap(arr[j],arr[j-1]);
        }
    }
}

int partition(int arr[], int first, int last) {
    int i = first-1;
    int j=first;
    int pivot = arr[last];
    for(;j<last;j++) {
        if(arr[j]<pivot) {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1], arr[last]);
    return i+1;
}

void recursiveQuickSort(int arr[], int first, int last) {
    if(first>=last) return;

    int pi = partition(arr,first,last);
    recursiveQuickSort(arr,0,pi-1);
    recursiveQuickSort(arr,pi+1,last);
}


int main() {
    int arr[] = {6,3,1,5,7,1,46,43,89,11,36};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"The original array is :";
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    recursiveQuickSort(arr,0,size-1);
    cout<<endl<<"The sorted array is :";
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}