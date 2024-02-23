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
    if(first>=last) {
        return;
    }
    int pi = partition(arr,first,last);
    quickSort(arr,first,pi-1);
    quickSort(arr,pi+1,last);
}



void insertionSort(int arr[], int size) {
    int i,j,temp;
    for(i=1;i<size;i++) {
        temp = arr[i];
        for(j=1;j>0;j--) {
            if(arr[j-1]>temp) {
                arr[j] = arr[j-1];
            }
        }
        arr[j] = temp;
    }
}

int main() {
    int arr[] = {4,3,7,13,52,23,52,12};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"The original array is : ";
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quickSort(arr,0,size-1);
    cout<<"The sorted array is : ";
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}

