//basic idea is to find the minimum element and put the element at the 0th index and the next smallest at the next index and so on.
#include <iostream>

using namespace std;

void selectionSort(int arr[], int size) {
    int min,pos,i,j;
    for(int i=0;i<size-1;i++) {
        min = arr[i];
        pos = i;
        for(int j=i+1;j<size;j++) {
            if(arr[j]<min) {
                min = arr[j];
                pos=j;
            }
        }
        swap(arr[i],arr[pos]);
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
    selectionSort(arr,size);
    cout<<"The sorted array is : ";
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}