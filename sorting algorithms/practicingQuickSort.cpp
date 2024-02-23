//practicing quickSort
#include <iostream>

using namespace std;

int partition(int arr[], int first, int last) {
    int pivot = arr[last];
    int i = first-1;
    int j=first;
    for(;j<last;j++) {
        if(arr[j]<pivot) {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[last]);
    return i+1;
}

void quickSort(int arr[], int first, int last) {
    if(first>=last)
    return;

    int pi = partition(arr,first,last);
    quickSort(arr,first,pi-1);
    quickSort(arr,pi+1,last);
}

int main() {
    int arr[] = {4,3,7,13,52,23,52,12};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"The original array is :";
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    quickSort(arr,0,size-1);
    cout<<endl<<"The sorted array is :";
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}