#include <iostream>

using namespace std;

void heapify(int i, int arr[], int size) {
    int li = 2 * i + 1;
    int ri = 2 * i + 2;

    int largest = i;
    if (li < size && arr[li] > arr[largest]) {
        largest = li;
    }
    if (ri < size && arr[ri] > arr[largest]) {
        largest = ri;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]
        heapify(largest, arr, size);
    }
}

void heapSort(int arr[], int size) {
    // Build the heap
    for (int i = (size / 2) - 1; i >= 0; i--) {
        heapify(i, arr, size);
    }

    // Extract elements from heap one by one
    for (int i = size - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(0, arr, i);
    }
}

int main() {
    int arr[] = {11, 4, 7, 23, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, size);

    for (auto i : arr) {
        cout << i << " ";
    }

    return 0;
}
