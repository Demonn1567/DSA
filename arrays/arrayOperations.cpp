#include <iostream>

using namespace std;

void insertion(int arr[], int size, int pos, int element) {
    for(int i=size-1;i>=pos;i--) {
        arr[i+1] = arr[i];
    }
    arr[pos] = element;
}

void deletion(int arr[], int size, int pos) {
    for(int i=pos;i<size-1;i++) {
        arr[i] = arr[i+1];
    }
}



int linearSearch(int arr[], int size, int element) {
    int loc=0;
    for(int i=0;i<size;i++) {
        if(arr[i]==element) {
            loc = i;
        }
    }
    if(loc!=0) {
        return loc;
    }
    
    return loc;
}

int binarySearch(int arr[], int size, int element) {
    int i=0,j=size-1;
    
    while(i<=j) {
        int mid = (i+j)/2;
        if(arr[mid]==element) {
            return mid;
        }
        if(arr[mid]<element) {
            i = mid+1;
        } 
        else {
            j=mid-1;
        }
    }
    return 0;
}
int minElement(int arr[], int size) {
    int min = arr[0];
    for(int i=1;i<size;i++) {
        if(arr[i]<min) {
            min = arr[i];
        }
    }
    return min;
}
int maxElement(int arr[], int size) {
    int max = arr[0];
    for(int i=1;i<size;i++) {
        if(arr[i]>max) {
            max = arr[i];
        }
    }
    return max;
}

int firstSecondMaxElement(int arr[], int size) {
    int max1, max2;
    if(arr[0]>arr[1]) {
        max1 = arr[0];
        max2 = arr[1];
    }
    else {
        max1 = arr[1];
        max2 = arr[0];
    }
    for(int i=2;i<size;i++) {
        if(arr[i]>max1) {
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i]>max2) {
            max2 = arr[i];
        }
    }
    return (max1, max2);
}



int main() {
    int arr[8] = {1,2,3,4,5,6,7};
    cout<<"The original array is : ";
    insertion(arr,8,7,8);
    for(auto i : arr) {
        cout<<i<<" ";
    }

    
    /* cout<<endl<<"The modified array is : ";
    
    deletion(arr,8,2);
    for(auto i : arr) {
        cout<<i<<" ";
    }
    cout<<endl;
    int x = linearSearch(arr,8,1);
    if(x!=0) {
        cout<<"element found at index"<<x;
    }
    else {
        cout<<"element not found";
    } */
    cout<<endl;
    int a = firstSecondMaxElement(arr,8);
    cout<<a;

    return 0;
}