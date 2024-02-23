#include <iostream>

using namespace std;

int linearSearch(int arr[], int size, int target) {
    int loc, flag = -1;
    for(int i=0;i<size;i++) {
        if(arr[i] == target) {
            loc = i;
            flag = 0;
        }
    }
    if(flag == -1)
    cout<<"Element not present.";

    else{
        cout<<"Element present at index :"<<loc;
    }
    return 0;  
}

int binarySearch(int arr[], int size, int target) {
    int i=0, j=size-1;
    while(i<=j) {
        int mid = (i+j)/2;
        if(arr[mid]==target) {
            return mid;
        }
        if(arr[mid]>target) {
            j = mid-1;
        }
        else 
        {
            i = mid+1;
        }
    }
    return -1;
}



int main () {
    int arr[] = {1,3,5,7,8,23};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 23;
    //linearSearch(arr,size,target);
    int x = binarySearch(arr,size,target);
    if(x==-1) {
        cout<<"Element not present";
    }
    else {
        cout<<"Element present at index :"<<x;
    }

    
    return 0;
}