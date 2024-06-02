#include <iostream>

using namespace std;

void merging(int a[],int b[],int c[],int size1, int size2) {
    int i=0,j=0,k=0;
    while(i<size1 && j<size2) {
        if(a[i]<b[j]) {
            c[k] = a[i];
            i++;
            k++;
        }
        else {
            c[k] = b[j];
            j++;
            k++;
        }
    }
    while(i<size1) {
        c[k] = a[i];
        i++;
        k++;
    }
    while(j<size2) {
        c[k] = b[j];
        j++;
        k++;
    }
}

int main() {
    int arr1[] = {5,7,2,1,7,8};
    int arr2[] = {8,3,1,9,2,1,0};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    int size3 = size1 +size2;
    int arr3[size3];
    

    merging(arr1,arr2,arr3,size1,size2);
    for(int i=0;i<size3;i++) {
        cout<<arr3[i]<<" ";
    }


    return 0;
}