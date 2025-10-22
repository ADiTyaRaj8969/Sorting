/*
8. Bucket Sort

Implement Bucket Sort for floating-point numbers in the range (0, 1).

Display the content of each bucket before and after sorting.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to perform Bucket Sort
void bucketSort(vector<float> &arr) {
    int n = arr.size();
    vector<vector<float>> buckets(n);

    // Distribute elements into buckets
    for(float num : arr) {
        int index = n * num; // bucket index
        buckets[index].push_back(num);
    }

    // Display buckets before sorting
    cout << "Buckets before sorting:\n";
    for(int i = 0; i < n; i++) {
        cout << "Bucket " << i << ": ";
        for(float num : buckets[i]) cout << num << " ";
        cout << endl;
    }

    // Sort individual buckets
    for(int i = 0; i < n; i++)
        sort(buckets[i].begin(), buckets[i].end());

    // Display buckets after sorting
    cout << "\nBuckets after sorting:\n";
    for(int i = 0; i < n; i++) {
        cout << "Bucket " << i << ": ";
        for(float num : buckets[i]) cout << num << " ";
        cout << endl;
    }

    // Merge buckets into original array
    int idx = 0;
    for(int i = 0; i < n; i++)
        for(float num : buckets[i])
            arr[idx++] = num;
}

int main() {
    vector<float> arr = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    
    cout << "Original array: ";
    for(float num : arr) cout << num << " ";
    cout << endl;

    bucketSort(arr);

    cout << "\nSorted array: ";
    for(float num : arr) cout << num << " ";
    cout << endl;

    return 0;
}

/*
Type: Non-comparison-based, Stable

Time Complexity:

Best Case: O(n + k) → When elements are uniformly distributed across buckets
Average Case: O(n + k) → n = number of elements, k = number of buckets
Worst Case: O(n²) → When all elements fall into a single bucket

Space Complexity:
Auxiliary Space: O(n + k) → Extra space for buckets

*/