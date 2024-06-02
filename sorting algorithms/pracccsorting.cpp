#include <iostream>

using namespace std;

void bubbleSort(int arr[], int size) {
    for(int i=0;i<size;i++) {
        for(int j=0;j<size-i-1;j++)  {
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
        int pos = i;
        for(int j = i+1;j<size;j++) {
            if(arr[j]<min) {
                min = arr[j];
                pos = j;
            }
        }
        swap(arr[i], arr[pos]);
    }
}

void insertionSort(int arr[], int size) {
    int i,j,temp;
    for(int i=1;i<size;i++) {
        temp = arr[i];
        for(int j = i;j>0&&arr[j-1]>temp;j--) {
            swap(arr[j],arr[j-1]);
        }
    }
}

int partition(int arr[], int first, int last) {
    int pivot = arr[last];
    int i = first-1;
    int j = first;
    for(;j<last;j++) {
        if(arr[j]<pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[last]);
    return i+1;
}

void recursiveQuickSort(int arr[], int first, int last) {
    if(first>=last) return;

    int pi = partition(arr, first,last);
    recursiveQuickSort(arr, first, pi-1);
    recursiveQuickSort(arr, pi+1,last);
}

void iterativeQuickSort(int arr[], int size) {
    int stack[size];
    int top=-1;
    stack[++top] = 0;
    stack[++top] = size-1;

    while(top>=0) {
        int high = stack[top--];
        int low = stack[top--];
        int pi = partition(arr, low,high);

        if(pi-1 > low) {
            stack[++top] = low;
            stack[++top] = pi-1;
        }
        if(pi + 1<high) {
            stack[++top] = pi+1;
            stack[++top] = high;
        }
    }
}



int main() {
    int arr[] = {7,3,64,21,6,7,3,789};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"The original array is ";
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //insertionSort(arr,size);
    iterativeQuickSort(arr,size);
    cout<<"The sorted array is ";
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}