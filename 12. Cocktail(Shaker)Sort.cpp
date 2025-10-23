#include <bits/stdc++.h>
using namespace std;

void cocktailSort(vector<int> &arr) {
    bool swapped = true;
    int start = 0, end = arr.size()-1;

    while(swapped) {
        swapped = false;
        // Forward pass
        for(int i=start; i<end; i++) {
            if(arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
        swapped = false;
        end--;
        // Backward pass
        for(int i=end-1; i>=start; i--) {
            if(arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                swapped = true;
            }
        }
        start++;
        cout << "Array after pass: ";
        for(int num : arr) cout << num << " ";
        cout << endl;
    }
}

int main() {
    vector<int> arr = {5, 1, 4, 2, 8, 0, 2};
    cout << "Original array: ";
    for(int num : arr) cout << num << " ";
    cout << endl;

    cocktailSort(arr);

    cout << "Sorted array (Cocktail Sort): ";
    for(int num : arr) cout << num << " ";
    cout << endl;
    return 0;
}

/*

Cocktail Sort (Shaker Sort)
Type: Comparison-based, Stable, In-place

Time Complexity:

Best Case: O(n) → When the array is already sorted
Average Case: O(n²) → Random order array
Worst Case: O(n²) → Reverse sorted array

Space Complexity:
Auxiliary Space: O(1) → In-place sorting

Characteristics:
Variation of Bubble Sort that passes in both directions each iteration

*/