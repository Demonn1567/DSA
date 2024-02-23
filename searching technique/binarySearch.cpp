#include <iostream>

using namespace std;

int binarySearch(int arr[],int size, int target, int loc) {
    int i=0,j=size-1;
    while(i<=j) {
        int mid = (i+j)/2;
        if(arr[mid]==target) {
            loc = mid;
            return loc;
        }
        else if(arr[mid]>target) {
            j = mid-1;
        }
        else {
            i = mid+1;
        }
    }
} 

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 7;
    int loc;
    int location =binarySearch(arr,size,target,loc);
    cout<<location;

    return 0;
}