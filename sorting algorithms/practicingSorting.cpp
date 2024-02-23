#include <iostream>

using namespace std;

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
    if(first>=last)
    return;

    int pi = partition(arr, first, last);
    quickSort(arr,first,pi-1);
    quickSort(arr,pi+1,last);
}

void selectionSort(int arr[], int size) {
    int min,pos,j;
    for(int i=0;i<size-1;i++) {
        min = arr[i];
        pos = i;
        for(j = i+1;j<size;j++) {
            if(arr[j]<min) {
                pos = j;
                min = arr[j];
            }
        }
        swap(arr[pos],arr[i]);
    }
}

    void insertionSort(int arr[], int size) {
        int temp,j;
        for(int i=0;i<size;i++) {
            int temp = arr[i];
            for(j=i;j>0&&arr[j-1]>temp;j--) {
                arr[j] = arr[j-1];
            }
            arr[j] = temp;
        }
    }

    void bubbleSort(int arr[], int size) {
        for(int i=0;i<size-1;i++) {
            for(int j=0;j<size-i-1;j++) {
                if(arr[j+1]<arr[j]) {
                    swap(arr[j],arr[j+1]);
                }
            }
        }
    }
    
    void countingSort(int arr[], int size) {
        int max = arr[0];
        for(int i=0;i<size;i++) {
            if(arr[i]>max) {
                max = arr[i];
            }
        }
        int count[max+1];
        for(int i=0;i<size;i++) {
            count[arr[i]]++;
        }
        int size1 = sizeof(count)/sizeof(count[0]);
        for(int i=1;i<size1;i++) {
            count[i] +=count[i-1];
        }
        int output[size];
        for(int i=0;i<size;i++) {
            output[count[arr[i]]-1] = arr[i];
            count[arr[i]]--;
        }
        for(int i=0;i<size;i++) {
            arr[i] = output[i];
        }
    }

    void countingRadixSort(int place, int arr[], int size) {
        int max = (arr[0]/place)%10;
        for(int i=0;i<size;i++) {
            if((arr[i]/place)%10 > max) {
                max = (arr[i]/place)%10;
            }
        }
        int count[max+1];
        for(int i=0;i<size;i++) {
            count[(arr[i]/place)%10]++;
        }
        int size1 = sizeof(count)/sizeof(count[0]);
        for(int i=1;i<size1;i++) {
            count[i]+=count[i-1];
        }
        int output[size];
        for(int i=size-1;i>=0;i--) {
            output[count[(arr[i]/place)%10]-1] = arr[i];
            count[(arr[i]/place)%10]--;
        }
        for(int i=0;i<size;i++) {
            arr[i] = output[i];
        }
    }
    void radixSort(int arr[], int size) {
        int max = arr[0];
        for(int i=0;i<size;i++) {
            if(arr[i]> max) {
                max = arr[i];
            }
        }
        int place = 1;
        while(max!=0) {
            countingRadixSort(place,arr,size);
            place*=10;
            max/=10;
        }
    }
    


int main() {
    int arr[] = {4,3,7,13,52,23,52,12};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"The original array is :";
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    countingSort(arr,size);
    cout<<endl<<"The sorted array is :";
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}