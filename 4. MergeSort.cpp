/*4. Merge Sort

Implement Merge Sort using recursion.

Print the left and right subarrays during each merge.

Display the sorted subarray after each merge step.*/

#include <iostream>
#include <vector>
using namespace std;

// Function to print an array
void printArray(const vector<int> &arr, int start, int end) {
    cout << "[ ";
    for (int i = start; i <= end; i++)
        cout << arr[i] << " ";
    cout << "]";
}

// Merge two halves
void merge(vector<int> &arr, int left, int mid, int right) {
    cout << "\nMerging...\n";
    cout << "Left: ";
    printArray(arr, left, mid);
    cout << " | Right: ";
    printArray(arr, mid + 1, right);
    cout << endl;

    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Merge process
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy remaining elements
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    cout << "Merged (Sorted Subarray): ";
    printArray(arr, left, right);
    cout << endl;
}

// Recursive Merge Sort
void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);      // Sort left half
        mergeSort(arr, mid + 1, right); // Sort right half
        merge(arr, left, mid, right);   // Merge halves
    }
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    cout << "Original Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    mergeSort(arr, 0, arr.size() - 1);
    cout << "\nFinal Sorted Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    return 0;
}

/*

Time Complexity:

Best Case: O(n log n) → Array already sorted or any arrangement
Average Case: O(n log n) → Random order array
Worst Case: O(n log n) → Reverse sorted array

Space Complexity:
Auxiliary Space: O(n) → Needs extra array for merging

*/