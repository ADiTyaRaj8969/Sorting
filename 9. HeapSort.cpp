#include <bits/stdc++.h>
using namespace std;

// Heapify a subtree rooted at index i
void heapify(vector<int> &arr, int n, int i) {
    int largest = i; // root
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(vector<int> &arr) {
    int n = arr.size();

    // Build max heap
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    cout << "Max-Heap: ";
    for(int num : arr) cout << num << " ";
    cout << endl;

    // Extract elements one by one
    for(int i = n-1; i >= 0; i--) {
        swap(arr[0], arr[i]); // Move max to end
        heapify(arr, i, 0);   // Heapify reduced heap
        cout << "After moving max to position " << i << ": ";
        for(int num : arr) cout << num << " ";
        cout << endl;
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    
    cout << "Original array: ";
    for(int num : arr) cout << num << " ";
    cout << endl;

    heapSort(arr);

    cout << "Sorted array: ";
    for(int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}

/*
Type: Comparison-based, Not stable, In-place

Time Complexity:

Best Case: O(n log n) → Heap operations dominate
Average Case: O(n log n)
Worst Case: O(n log n) → Consistent regardless of input

Space Complexity:
Auxiliary Space: O(1) → In-place sorting

*/