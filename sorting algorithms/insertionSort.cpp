#include <iostream>

using namespace std;

void insertionSort(int arr[], int size) {
    int i,j,temp;
    for(i=1;i<size;i++) {
        temp = arr[i];
        for(j=i;j>0&&arr[j-1]>temp;j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}

int main() {
    int arr[] = {5,4,3,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"The original array is : ";
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    insertionSort(arr,size);
    cout<<"The sorted array is : ";
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}