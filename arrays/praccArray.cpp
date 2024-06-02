#include <iostream>

using namespace std;

void insertion(int arr[], int size, int element, int position) {
    for(int i=size-1;i>=position;i--) {
        arr[i+1] = arr[i];
    }
    arr[position] = element;
}

void deletion(int arr[], int size, int pos) {
    for(int i=pos;i<size-1;i++) {
        arr[i] = arr[i+1];
    }
}

int linearSearch(int arr[], int size, int element) {
    int loc = -1;
    for(int i=0;i<size;i++) {
        if(arr[i]==element) {
            loc = i;
        }
    }
    if(loc==-1) {
        cout<<"Element not found";
        return loc;
    }
    else {
        cout<<"Element found at index"<<loc;
        return loc;
    }
}

int recursiveLinearSearch(int arr[], int size, int element) {
    if(size==0) return -1;

    else if(arr[size-1]== element) {
        return size-1;
    }
    return recursiveLinearSearch(arr, size-1, element);
}

int binarySearch(int arr[], int size, int element) {
    int i=0, j=size-1;
    while(i<=j) {
        int mid = (i+j)/2;
        if(arr[mid]==element) {
            return mid;
        }
        if(arr[mid]<element) {
            i = mid+1;
        }
        else {
            j= mid-1;
        }
    }
    return -1;
}

int recursiveBinarySearch(int arr[], int low, int high, int element) {
    if(low > high) {
        return -1;
    }
    int mid = (low+high) /2;
    if(arr[mid]== element) {
        return mid;
    }
    else if(arr[mid]<element) {
        return recursiveBinarySearch(arr, mid+1, high, element);
    }
    else {
        return recursiveBinarySearch(arr, low, mid-1, element);
    }
}

void merge(int a[], int b[], int c[], int size1, int size2) {
    int i=0, j=0, k=0;
    while(i<size1 && j<size2) {
        if(a[i]<b[j]) {
            c[k++] = a[i++];
        }
        else {
            c[k++] = b[j++];
        }
    }
    while(i<size1) {
        c[k++] = a[i++];
    }
    while(j<size2) {
        c[k++] = b[j++];
    }
}

//rotating an Array by k steps
void reverse(int arr[], int size, int i, int j) {
    while(i<=j) {
        swap(arr[i],arr[j]);
        i++;j--;
    }
}

void rotateArray(int arr[], int size, int k) {
    if(k>size) {
        k=k%size;
    }
    reverse(arr, size, 0, size-1);
    reverse(arr, size, 0, k-1);
    reverse(arr, size, k,size-1);
}

int main() {
    /* int arr1[] = {2,7,9,11,23};
    int arr2[] = {1,3,5,7,9};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    int size3 = size1 + size2;
    int arr3[size3];
    

    merge(arr1,arr2,arr3,size1,size2);
    for(auto i:arr3)
     {
        cout<<i<<" ";
     }     */
    int arr[] = {1,2,3,4,5,6,7,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    rotateArray(arr,size, 3);

    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }

     
    return 0;
}