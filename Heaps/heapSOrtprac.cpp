#include <iostream>

using namespace std;

void Heapify(int i, int arr[], int size) {
    int li = 2*i+1;
    int ri = 2*i+2;
    int largest = i;
    if(li<size && arr[li]>arr[largest]) {
        largest  =li;
    }
    if(ri<size && arr[ri]>arr[largest]) {
        largest = ri;
    }

    if(largest!=i) {
        swap(arr[i], arr[largest]);
        Heapify(largest,arr,size);
    }
}

void insert(int arr[], int* size, int item) {
    (*size)++;
    arr[*size-1] = item;

    for(int i=(*size/2)-1;i>=0;i--) {
        Heapify(i,arr,*size);
    }
}

void deleteNode(int arr[], int* size) {

    swap(arr[0],arr[*size-1]);
    (*size)--;

    for(int i=(*size/2)-1;i>=0;i--) {
        Heapify(i,arr,*size);
    }

}

void heapSort(int arr[], int* size) {
    for(int j=0;j<*size;j++) {
        insert(arr,size,arr[j]);
    }
    while(*(size)>0) {
        deleteNode(arr,size);
        
    }

}

int main() {
    int arr[] = {32,24,44,21,55,47,67,49};
    int size = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr,&size);

    

    

    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}