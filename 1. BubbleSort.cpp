/* 1. Bubble Sort

Write a program to sort an array using Bubble Sort.

Modify Bubble Sort to stop early if the array becomes sorted before all passes.

Count and display the number of swaps performed during sorting. */


#include<bits/stdc++.h>
using namespace std;

//  Basic Bubble Sort
void bubbleSortBasic(vector<int> nums) {
    cout << "\n--- Basic Bubble Sort ---\n";
    int n = nums.size();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }

    cout << "Sorted array: ";
    for (int x : nums) cout << x << " ";
    cout << endl;
}

// 2️ Optimized Bubble Sort (Early Stop if Sorted)
void bubbleSortOptimized(vector<int> nums) {
    int n = nums.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            cout << "Array became sorted early at pass " << i + 1 << endl;
            break;
        }
    }

    cout << "Sorted array: ";
    for (int x : nums) cout << x << " ";
    cout << endl;
}

// 3️ Bubble Sort with Swap Counter
void bubbleSortCount(vector<int> nums) {
    cout << "\n--- Bubble Sort with Swap Counter ---\n";
    int n = nums.size();
    int swapCount = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                swapCount++;
            }
        }
    }

    cout << "Sorted array: ";
    for (int x : nums) cout << x << " ";
    cout << "\nTotal swaps performed: " << swapCount << endl;
}

// 🧠 Main Function
int main() {
    vector<int> data = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original array: ";
    for (int x : data) cout << x << " ";
    cout << endl;

    bubbleSortBasic(data);
    bubbleSortOptimized(data);
    bubbleSortCount(data);

    return 0;
}


/*

Time Complexity:

Best Case: O(n) → When the array is already sorted (with optimized version that stops if no swaps occur)
Average Case: O(n²) → Random order array
Worst Case: O(n²) → Reverse sorted array

Space Complexity:
Auxiliary Space: O(1) → In-place sorting, no extra array needed

*/