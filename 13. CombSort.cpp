#include <bits/stdc++.h>
using namespace std;

void combSort(vector<int> &arr) {
    int n = arr.size();
    int gap = n;
    const double shrink = 1.3;
    bool sorted = false;

    while(!sorted) {
        gap = int(gap / shrink);
        if(gap <= 1) {
            gap = 1;
            sorted = true;
        }

        for(int i=0; i+gap<n; i++) {
            if(arr[i] > arr[i+gap]) {
                swap(arr[i], arr[i+gap]);
                sorted = false;
            }
        }
        cout << "Array after gap " << gap << ": ";
        for(int num : arr) cout << num << " ";
        cout << endl;
    }
}

int main() {
    vector<int> arr = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    cout << "Original array: ";
    for(int num : arr) cout << num << " ";
    cout << endl;

    combSort(arr);

    cout << "Sorted array (Comb Sort): ";
    for(int num : arr) cout << num << " ";
    cout << endl;
    return 0;
}

/*
Type: Comparison-based, Not stable, In-place

Time Complexity:
Best Case: O(n log n) → When array is nearly sorted
Average Case: O(n² / 2^p) ≈ O(n²) → Depends on shrink factor and gap sequence
Worst Case: O(n²) → Reverse sorted array or bad gap sequence

Space Complexity:
Auxiliary Space: O(1) → In-place sorting

*/