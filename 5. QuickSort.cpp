/*5. Quick Sort

Implement Quick Sort using recursion.

Use the first element as pivot and display array changes after each partition.

Modify the program to use the last element as pivot.

Implement median-of-three Quick Sort and compare the number of recursive calls. */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countFirst = 0, countLast = 0, countMedian = 0;

void printArray(const vector<int>& a) { for (int x : a) cout << x << " "; cout << endl; }

// --- 1. Quick Sort: First Element Pivot ---
int partitionFirst(vector<int>& a, int l, int h) {
    int p = a[l], i = l + 1, j = h;
    while (true) {
        while (i <= h && a[i] <= p) i++;
        while (a[j] > p) j--;
        if (i >= j) break;
        swap(a[i], a[j]);
    }
    swap(a[l], a[j]);
    cout << "Pivot(First=" << p << "): "; printArray(a);
    return j;
}
void quickFirst(vector<int>& a, int l, int h) {
    countFirst++;
    if (l < h) {
        int p = partitionFirst(a, l, h);
        quickFirst(a, l, p - 1);
        quickFirst(a, p + 1, h);
    }
}

// --- 2. Quick Sort: Last Element Pivot ---
int partitionLast(vector<int>& a, int l, int h) {
    int p = a[h], i = l - 1;
    for (int j = l; j < h; j++)
        if (a[j] <= p) swap(a[++i], a[j]);
    swap(a[i + 1], a[h]);
    cout << "Pivot(Last=" << p << "): "; printArray(a);
    return i + 1;
}
void quickLast(vector<int>& a, int l, int h) {
    countLast++;
    if (l < h) {
        int p = partitionLast(a, l, h);
        quickLast(a, l, p - 1);
        quickLast(a, p + 1, h);
    }
}

// --- 3. Quick Sort: Median-of-Three Pivot ---
int medianOfThree(vector<int>& a, int l, int h) {
    int m = (l + h) / 2;
    if (a[m] < a[l]) swap(a[m], a[l]);
    if (a[h] < a[l]) swap(a[h], a[l]);
    if (a[m] > a[h]) swap(a[m], a[h]);
    swap(a[l], a[m]);
    return a[l];
}
int partitionMedian(vector<int>& a, int l, int h) {
    int p = medianOfThree(a, l, h), i = l + 1, j = h;
    while (true) {
        while (i <= h && a[i] <= p) i++;
        while (a[j] > p) j--;
        if (i >= j) break;
        swap(a[i], a[j]);
    }
    swap(a[l], a[j]);
    cout << "Pivot(Median=" << p << "): "; printArray(a);
    return j;
}
void quickMedian(vector<int>& a, int l, int h) {
    countMedian++;
    if (l < h) {
        int p = partitionMedian(a, l, h);
        quickMedian(a, l, p - 1);
        quickMedian(a, p + 1, h);
    }
}

int main() {
    vector<int> arr = {29, 10, 14, 37, 13, 25, 3, 8};

    vector<int> a1 = arr, a2 = arr, a3 = arr;
    cout << "Original: "; printArray(arr);

    cout << "\n-- First Element Pivot --\n";
    quickFirst(a1, 0, a1.size() - 1);
    cout << "Sorted: "; printArray(a1);
    cout << "Calls: " << countFirst << endl;

    cout << "\n-- Last Element Pivot --\n";
    quickLast(a2, 0, a2.size() - 1);
    cout << "Sorted: "; printArray(a2);
    cout << "Calls: " << countLast << endl;

    cout << "\n-- Median-of-Three Pivot --\n";
    quickMedian(a3, 0, a3.size() - 1);
    cout << "Sorted: "; printArray(a3);
    cout << "Calls: " << countMedian << endl;

    return 0;
}

/*
Time Complexity:

Best Case: O(n log n) → Pivot divides array into nearly equal halves
Average Case: O(n log n) → Random order array
Worst Case: O(n²) → Pivot is always the smallest or largest element (e.g., already sorted array with first/last pivot)

Space Complexity:
Auxiliary Space: O(log n) → Recursion stack for in-place Quick Sort

In-place: Yes, no extra array needed

*/