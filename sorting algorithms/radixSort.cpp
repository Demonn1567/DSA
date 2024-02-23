#include <iostream>

using namespace std;
void countingSort(int place, int arr[], int size);

void radixSort(int arr[], int size) {
    int max = arr[0];
    for(int i=1;i<size;i++) {
        if(arr[i]>max) {
            max = arr[i];
        }
    }
    int place = 1;
    while(max!=0) {
        countingSort(place, arr, size);
        place*=10;
        max/=10;
    }
}

void countingSort(int place, int arr[], int size) {
    int max = (arr[0]/place)%10;
    for(int i=1;i<size;i++) 
    {
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
int main() {
    int arr[] = {4,3,7,13,52,23,52,12};
    int size = sizeof(arr)/sizeof(arr[0]);
    radixSort(arr, size);
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}