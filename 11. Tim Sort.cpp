#include <bits/stdc++.h>
using namespace std;

const int RUN = 32;

// Insertion Sort for small runs
void insertionSort(vector<int> &arr, int left, int right) {
    for(int i = left+1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while(j >= left && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

// Merge function
void merge(vector<int> &arr, int l, int m, int r) {
    vector<int> left(arr.begin()+l, arr.begin()+m+1);
    vector<int> right(arr.begin()+m+1, arr.begin()+r+1);
    int i=0,j=0,k=l;
    while(i<left.size() && j<right.size()) {
        arr[k++] = (left[i]<=right[j]) ? left[i++] : right[j++];
    }
    while(i<left.size()) arr[k++] = left[i++];
    while(j<right.size()) arr[k++] = right[j++];
}

// Tim Sort main function
void timSort(vector<int> &arr) {
    int n = arr.size();
    // Sort small runs with insertion sort
    for(int i=0; i<n; i+=RUN) {
        insertionSort(arr, i, min(i+RUN-1, n-1));
    }
    // Merge runs
    for(int size=RUN; size<n; size *= 2) {
        for(int left=0; left<n; left += 2*size) {
            int mid = min(left+size-1, n-1);
            int right = min(left+2*size-1, n-1);
            if(mid < right)
                merge(arr, left, mid, right);
        }
    }
    cout << "Sorted array (Tim Sort): ";
    for(int num : arr) cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {5, 21, 7, 23, 19, 2, 1, 15};
    cout << "Original array: ";
    for(int num : arr) cout << num << " ";
    cout << endl;
    timSort(arr);
    return 0;
}

/*
Type: Comparison-based, Stable
Time Complexity:

Best Case: O(n) → When the array is already partially sorted
Average Case: O(n log n)
Worst Case: O(n log n) → Merges dominate the performance

Space Complexity:
Auxiliary Space: O(n) → Uses temporary arrays for merging

Characteristics:
Hybrid of Merge Sort + Insertion Sort

*/
