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


int main() {
    int arr[100];
    int size=0;

    insert(arr,&size,36);
    insert(arr,&size,16);
    insert(arr,&size,40);
    insert(arr,&size,43);
    insert(arr,&size,12);
    insert(arr,&size,78);
    insert(arr,&size,22);
    insert(arr,&size,50);
    insert(arr,&size,60);
    insert(arr,&size,48);
    deleteNode(arr, &size);

    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}