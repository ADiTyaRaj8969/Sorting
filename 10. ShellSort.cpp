#include <bits/stdc++.h>
using namespace std;

void shellSort(vector<int> &arr) {
    int n = arr.size();

    // Start with a big gap, then reduce the gap
    for(int gap = n/2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size
        for(int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while(j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        // Display array after current gap
        cout << "After gap " << gap << ": ";
        for(int num : arr) cout << num << " ";
        cout << endl;
    }
}

int main() {
    vector<int> arr = {12, 34, 54, 2, 3};

    cout << "Original array: ";
    for(int num : arr) cout << num << " ";
    cout << endl;

    shellSort(arr);

    cout << "Sorted array: ";
    for(int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}

/*
Type: Comparison-based, Not stable, In-place

Time Complexity (Worst Case):
Depends on the gap sequence:
Original Shell’s gaps: O(n²)
Using better sequences (e.g., Hibbard, Sedgewick): O(n^(3/2)) to O(n^(4/3))
Best Case: O(n log n) (for some sequences, nearly sorted array)
Average Case: ~O(n^(3/2)) for common sequences

Space Complexity:
Auxiliary Space: O(1) → In-place

*/