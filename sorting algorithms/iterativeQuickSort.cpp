#include <iostream>
#include <stack>


using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    int j = low;
    for(;j<high;j++) {
        if(arr[j]<pivot) {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void iterativeQuickSort(int arr[], int size) {
    int stack[size];
    int top=-1;
    stack[++top] = 0;
    stack[++top] = size-1;

    while(top>=0) {
        int high = stack[top--];
        int low = stack[top--];
        
        int pi = partition(arr,low,high);
        if(pi-1>low) {
            stack[++top] = low;
            stack[++top] = pi-1;
        }
        if(pi+1<high) {
            stack[++top] = pi+1;
            stack[++top] = high;
        }

    }
}

int main() {
    int arr[] = {6,2,1,6,8,2,7,3};
    int size = sizeof(arr)/sizeof(arr[0]);

    iterativeQuickSort(arr,size);
    for(auto i : arr) {
        cout<<i<<" ";
    }

    return 0;
}