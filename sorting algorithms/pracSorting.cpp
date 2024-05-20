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


//QuickSort
int partition(int arr[], int first, int last) {
    int pivot = arr[last];
    int i = first-1;
    int j = first;
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
    if(first>=last) return;

    int pi = partition(arr, first,last);
    quickSort(arr,first,pi-1);
    quickSort(arr,pi+1,last);
}

//mergeSort
void merge(int arr[], int low, int mid, int high) {
    int l = mid-low+1;
    int r = high-mid;
    int a1[l], a2[r];

    for(int i=0;i<l;i++) {
        a1[i] = arr[low+i];
    }
    for(int j=0;j<r;j++) {
        a2[j] = arr[mid+1+j];
    }
    int i=0,j=0,k=low;
    while(i<l&&j<r) {
        if(a1[i]<=a2[j]) {
            arr[k++] = a1[i++];
        }
        else {
            arr[k++] = a2[j++];
        }
    }
    while(i<l) {
        arr[k++] = a1[i++];
    }
    while(j<r) {
        arr[k++] = a2[j++];
    }
}

void mergeSort(int arr[], int low, int high) {
    if(low>=high) {
        return;
    }
    int mid = (low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}


int main() {
    int arr[] = {45,3,71,2,9,11,0,3,2,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"The original array is : ";
    for(auto i : arr) {
        cout<<i<<" ";
    }
    mergeSort(arr,0,size-1);
    cout<<endl<<"The sorted array is : ";
    for(auto i : arr) {
        cout<<i<<" ";
    }
    return 0;
}