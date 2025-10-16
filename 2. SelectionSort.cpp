/* 2. Selection Sort

Implement Selection Sort to arrange an array in ascending order.

Modify Selection Sort to arrange numbers in descending order.

Display the index positions of the selected minimum element at each iteration.*/

#include <iostream>
#include <vector>
using namespace std;

//  Selection Sort in Ascending Order
void selectionSortAscending(vector<int> nums) {
    int n = nums.size();

    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i; // assume current index is minimum
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[minIndex])
                minIndex = j;
        }
        cout << "Pass " << i + 1 << ": Minimum element index = " << minIndex << endl;
        swap(nums[i], nums[minIndex]);
    }

    cout << "Sorted array (Ascending): ";
    for (int x : nums) cout << x << " ";
    cout << endl;
}

//  Selection Sort in Descending Order
void selectionSortDescending(vector<int> nums) {
    int n = nums.size();

    for (int i = 0; i < n - 1; ++i) {
        int maxIndex = i; // assume current index is maximum
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] > nums[maxIndex])
                maxIndex = j;
        }
        cout << "Pass " << i + 1 << ": Maximum element index = " << maxIndex << endl;
        swap(nums[i], nums[maxIndex]);
    }

    cout << "Sorted array (Descending): ";
    for (int x : nums) cout << x << " ";
    cout << endl;
}

//  Main Function
int main() {
    vector<int> data = {64, 25, 12, 22, 11};

    cout << "Original array: ";
    for (int x : data) cout << x << " ";
    cout << endl;

    selectionSortAscending(data);
    selectionSortDescending(data);

    return 0;
}

/*

Time Complexity:

Best Case: O(n²) → Even if the array is already sorted, it still performs comparisons
Average Case: O(n²) → Random order array
Worst Case: O(n²) → Reverse sorted array

Space Complexity:
Auxiliary Space: O(1) → In-place sorting, no extra array needed

*/