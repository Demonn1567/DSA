#include <iostream>

using namespace std;

void bubbleSort(int arr[], int size) {
    for(int i=0;i<size-1;i++) {
        for(int j=0;j<size-i-1;j++) {
            if(arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size) {
    for(int i=0;i<size-1;i++) {
        int min = arr[i];
        int pos=i;
        for(int j=i+1;j<size;j++) {
            if(arr[j]<min) {
                min = arr[j];
                pos=j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
}

void insertionSort(int arr[], int size) {
    int i,j,temp;
    for(i=1;i<size;i++) {
        temp = arr[i];
        for(j=i;j>0&&arr[j-1]>temp;j--) {
            swap(arr[j],arr[j-1]);
        }
        
    }
}


//QuickSort
int partition(int arr[], int first, int last) {
    int pivot = arr[last];
    int i=first-1;
    int j=first;
    for(;j<last;j++) {
        if(arr[j]<pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];  
    arr[i+1] = arr[last];
    arr[last] = temp;

    return i+1;
}

void quickSort(int arr[], int first, int last) {
    if(first>=last) {
        return;
    }

    int pi = partition(arr,first,last);
    quickSort(arr,0,pi-1);
    quickSort(arr,pi+1,last);
}





int main() {
    int arr[] = {6,3,1,5,7,1,46,43,89,11,36};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"The original array is :";
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    insertionSort(arr,size);
    cout<<endl<<"The sorted array is :";
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}