/* 7. Radix Sort

Implement Radix Sort using Counting Sort as a subroutine.

Show the array after sorting by each digit place (1s, 10s, 100s...).  */

#include <bits/stdc++.h>
using namespace std;

// Counting Sort for Radix Sort (sorts by digit place)
void countingSortByDigit(vector<int> &arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Count occurrences of digits
    for(int i = 0; i < n; i++)
        count[(arr[i]/exp)%10]++;

    // Build cumulative frequency
    for(int i = 1; i < 10; i++)
        count[i] += count[i-1];

    // Build output array
    for(int i = n-1; i >= 0; i--) {
        output[count[(arr[i]/exp)%10] - 1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }

    arr = output;

    // Display array after current digit sort
    cout << "After sorting with exp " << exp << ": ";
    for(int num : arr) cout << num << " ";
    cout << endl;
}

// Radix Sort main function
void radixSort(vector<int> &arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    for(int exp = 1; maxVal/exp > 0; exp *= 10)
        countingSortByDigit(arr, exp);
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    cout << "Original array: ";
    for(int num : arr) cout << num << " ";
    cout << endl;

    radixSort(arr);

    cout << "Sorted array: ";
    for(int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}

/*

Type: Non-comparison-based, Stable

Time Complexity:
Best Case: O(nk) → n = number of elements, k = number of digits
Average Case: O(nk)
Worst Case: O(nk)

Space Complexity:
Auxiliary Space: O(n + k) → Mainly for counting sort used on each digit

*/