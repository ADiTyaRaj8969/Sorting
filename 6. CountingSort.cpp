/* 6. Counting Sort

Implement Counting Sort for non-negative integers.

Display the count array and cumulative frequency array after each step. */

#include <bits/stdc++.h>
using namespace std;

// Function to find maximum element
int findMax(vector<int> &arr) {
    int maxVal = arr[0];
    for(int num : arr)
        if(num > maxVal) maxVal = num;
    return maxVal;
}

// Function to build count array
vector<int> buildCountArray(vector<int> &arr, int maxVal) {
    vector<int> count(maxVal + 1, 0);
    for(int num : arr)
        count[num]++;
    
    cout << "Count array: ";
    for(int c : count) cout << c << " ";
    cout << endl;
    return count;
}

// Function to build cumulative frequency array
vector<int> buildCumulativeArray(vector<int> &count) {
    vector<int> cumFreq = count;
    for(size_t i = 1; i < cumFreq.size(); i++)
        cumFreq[i] += cumFreq[i-1];
    
    cout << "Cumulative frequency array: ";
    for(int c : cumFreq) cout << c << " ";
    cout << endl;
    return cumFreq;
}

// Counting Sort function
void countingSort(vector<int> &arr) {
    int maxVal = findMax(arr);
    vector<int> count = buildCountArray(arr, maxVal);
    vector<int> cumFreq = buildCumulativeArray(count);

    vector<int> sorted(arr.size());
    for(int i = arr.size()-1; i >= 0; i--) {
        sorted[cumFreq[arr[i]] - 1] = arr[i];
        cumFreq[arr[i]]--;
    }

    arr = sorted;
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    cout << "Original array: ";
    for(int num : arr) cout << num << " ";
    cout << endl;

    countingSort(arr);

    cout << "Sorted array: ";
    for(int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}

/*
Type: Non-comparison-based, Stable

Time Complexity:
Best Case: O(n + k) → Always depends on the number of elements (n) and the range of input (k)
Average Case: O(n + k)
Worst Case: O(n + k)

Space Complexity:
Auxiliary Space: O(k) → Uses count array of size equal to the range of input elements

*/