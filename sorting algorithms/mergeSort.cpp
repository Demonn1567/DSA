#include <iostream>

using namespace std;

void merge(int arr[],int l, int mid, int r) {
    int size1 = mid-l+1;
    int size2 = r-mid;
    int a1[size1],a2[size2];
    for(int i=0;i<size1;i++) {
        a1[i] = arr[l+i];
    }
    for(int j=0;j<size2;j++) {
        a2[j] = arr[mid+j+1];
    }
    int i=0,j=0,k=l;
    while(i<size1&&j<size2) {
        if(a1[i]<a2[j]) {
            arr[k++] = a1[i++]; 
        }
        else {
            arr[k++] = a2[j++];
        }
    }
    while(i<size1) {
        arr[k++] = a1[i++];
    }
    while(j<size2) {
        arr[k++] = a2[j++];
    }
}

void mergeSort(int arr[], int first, int last) {
    if (first >= last) {
        return;
    }
    int mid = (last + first) / 2;
    mergeSort(arr, first, mid);
    mergeSort(arr, mid + 1, last);
    merge(arr, first, mid, last);
}


int main() {
    int arr[] = {5,4,3,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"The original array is : ";
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergeSort(arr,0,size-1);
    cout<<"The sorted array is : ";
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}


/* T(N) = T(N/2) + T(N/2) +N 

T(N/2) = T(N/4) + T(N/4) + N/2

T(N/4) = T(N/8) + T(N/8) + N/4

T(N) = 2T(N/2) + N 
T(N) = 4T(N/4) + 2N 
T(N) = 8T(N/8) + 3N

T(N) = 2^k * (T(N/2^k)) +k*N 


after some time, 
let n/2^k = 1
n = 2^k 
taking log 
logn = klog2
log2 base 2 = 1
logn = k

putting k in formula

T(N) = 2^logn * (T(1)) + Nlogn
T(N) = 2^logn + Nlogn
T(N) = N + NlogN 
T(N) = N(1+ logN)
1 neglected being constant
T(N) = NlogN */


