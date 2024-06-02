#include <iostream>

using namespace std;

void merge(int a[], int b[], int c[], int size1, int size2) {
    int i=0,j=0,k=0;
    while(i<size1 &&j<size2) {
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

int main() {
    int arr1[] = {2,7,9,11,23};
    int arr2[] = {1,3,5,7,9};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    int size3 = size1 + size2;
    int arr3[size3];
    

    merge(arr1,arr2,arr3,size1,size2);
    for(auto i:arr3)
     {
        cout<<i<<" ";
     }    
    return 0;
}