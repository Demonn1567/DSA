#include <iostream>
#include <stack>

using namespace std;

void nextGreaterElement(int arr[], int size, int nge[]) {
    stack<int> st;
    for (int i = 0; i <= 2 * size - 1; i++) {
        while (!st.empty() && st.top() <= arr[i % size]) {
            st.pop();
        }
        if (i < size) {
            if (!st.empty()) {
                nge[i] = st.top();
            } else {
                nge[i] = -1;
            }
        }
        st.push(arr[i % size]);
    }
}

int main() {
    int arr[] = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int nge[size]; // Declare the array to store the next greater elements
    nextGreaterElement(arr, size, nge);
    for (int i = 0; i < size; i++) {
        cout << nge[i] << " ";
    }
    return 0;
}
