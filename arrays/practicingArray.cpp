#include <iostream>

using namespace std;

void insert(int arr[],int &size, int element, int position) {
    
    for(int i=size-2;i>=position;i--) {
        arr[i+1] = arr[i];
    }
    arr[position] = element;
    size++;
}

int deleteElement(int arr[], int &size, int position)
{
    int item = arr[position];
    for(int i=position;i<size-1;i++) {
        arr[i] = arr[i+1];
    }
    size--;
    return item;
}

int linearSearch(int arr[],int &size, int element) {
    int loc=-1;
    for(int i=0;i<size;i++) {
        if(arr[i]==element) {
            loc=i;
        }
    }
    if(loc==-1) {
        cout<<"Element not found";
        return -1;
    }
    cout<<"Element found at index :"<<loc;
    return loc;
}

int binarySearch(int arr[], int &size, int element) {
    int i=0,j=size-1;
    while(i<=j) {
        int mid = (i+j)/2;
        if(arr[mid]==element) {
            cout<<"Element found at index : "<<mid;
            return mid;
        }
        if(arr[mid]<element) {
            i=mid+1;
        }
        else {
            j=mid-1;
        }
    }
    cout<<"Element not found";
    return -1;
}

int maxMinElement(int arr[], int &size) {
    int max = arr[0],min=arr[0];
    for(int i=1;i<size;i++) {
        if(arr[i]>max) {
            max = arr[i];
        }
        if(arr[i]<min) {
            min = arr[i];
        }
    }
    cout<<"The maximum and minimum elements of the array are : "<<max<<" & "<<min;
    return 0;
}

int secondMaxElement(int arr[], int &size) {
    int max1,max2;
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
            int temp = max1;
            max1 = arr[i];
            max2 = temp;
        }
        else if(arr[i]>max2) {
            max2 = arr[i];
        }
    }
    cout<<"The first and second maximum elements of the array are :"<<max1<<" & "<<max2;
    return 0;
}

void oddElements(int arr[], int size) { //multiplying all odd indexed elements to its second multiple and increment all even indexed values by 10
    for(int i=0;i<size;i++) {
        if(i%2==0) {
            arr[i]+=10;
        }
        else {
            arr[i]*=2;
        }
    }

}

int pairs(int arr[], int size, int value) { //find total number of pairs in the array is sum is given to the given value x
    int count = 0;
    for(int i=0;i<size;i++) {
        for(int j=i+1;j<size;j++) {
            if(arr[i]+arr[j]==value) {
                count++;
            }
        }
    }
    cout<<"The number of pairs making the number"<<value<<"are : "<<count; 
    return count;
}

void reverse(int arr[], int size, int i,int j) {
    while(i<=j) {
        int temp = arr[i];
        arr[i]=arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

void rotateArrayKSteps(int arr[], int size, int k) {
    if(k>size) {
        k%=size;
    }

    reverse(arr,size,0,size-1);
    reverse(arr,size,0,k-1);
    reverse(arr,size,k,size-1);
    
}

void missingElement(int arr[], int size) {
    int element;
    int sum=0;
    int realSum=0;
    for(int i=0;i<size;i++) {
        sum+=arr[i];
    }
    realSum = ((size+1)*(size+2))/2;
    element = realSum-sum;
    cout<<"The missing element is :"<<element;
}

int duplicateElement(int arr[], int size) {
    int duplicate;
    for(int i=0;i<size;i++) {
        for(int j=i+1;j<size;j++) {
            if(arr[i]==arr[j]) {
                duplicate = arr[i];
            }
        }
    }
    cout<<"Duplicate element is :"<<duplicate;
    return 0;
}

int uniqueElement(int arr[], int size) {
    for(int i=0;i<size;i++) {
        bool flag = false;
        for(int j=i+1;j<size;j++) {
            if(arr[i]==arr[j]) {
                flag = true;
            }
        }
        if(flag==false) {
            cout<<"The unique element is :"<<arr[i];
            break;
        }
    }
    return 0;
}

void mergeTwoSortedArrays(int arr1[], int arr2[], int size1, int size2,int arr3[]) {
    arr3[size1+size2];
    int left=0,right=0,index=0;
    while(left < size1 &&right<size2) {
        if(arr1[left]<=arr2[right]) {
            arr3[index++] = arr1[left++];
        }
        else {
            arr3[index++] = arr2[right++];
        }
    }
    while(left<size1) {
        arr3[index++] = arr1[left++];
    }
    while(right<size2) {
        arr3[index++] = arr2[right++];
    }
}

void threeLargestElements(int arr[], int size) {
    int first,second,third;
    first=second=third=INT_MIN;
    for(int i=0;i<size;i++) {
        if(arr[i]>first) {
            third = second;
            second = first;
            first = arr[i];
        }
        else if(arr[i]>second &&arr[i]!=first) {
            third = second;
            second = arr[i];
        }
        else if(arr[i]>third &&arr[i]!=second &&arr[i]!=first) {
            third = arr[i];
        }
    }
    cout<<"The three largest elements are :"<<first<<", "<<second<<", "<<third;

}

void moveAllZeroes(int arr[], int size) {
    int count=0;
    for(int i=0;i<size;i++) {
        if(arr[i]!=0) {
            arr[count++] = arr[i];
        } 
    }
    while(count<size) {
        arr[count++] =0;
    }
}


int main() {
    
    int arr1[]  = {1,3,5,7};
    int arr2[] = {2,4,6,8};
    
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    int arr3[size1+size2];

    int arr[] = {1,0,4,0,6,8,9};
    int size= sizeof(arr)/sizeof(arr[0]);
    insert(arr,size,-5,1);
    






    /* mergeTwoSortedArrays(arr1,arr2,size1,size2,arr3);
    for(int i=0;i<size1+size2;i++) {
        cout<<arr3[i]<<" ";
    } */
    /* moveAllZeroes(arr,size);
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    } */

    /* cout<<"The original array is :";
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //missingElement(arr,size);
    uniqueElement(arr,size);
    /* //pairs(arr,size,8);
    //oddElements(arr,size);
    rotateArrayKSteps(arr,size,10);
    //deleteElement(arr,size,5);
    cout<<"The modified array is :";
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    } */ 
    return 0;
}