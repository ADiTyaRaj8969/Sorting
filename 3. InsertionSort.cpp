/*
3. Insertion Sort

Write a program to implement Insertion Sort.

Print the array after every insertion step.

Sort an array of strings alphabetically using Insertion Sort.
*/

#include<bits/stdc++.h>
using namespace std;

// Function 1: Insertion Sort for integers (prints after each step)
void insertionSortInt(vector<int> &arr) {
    int n = arr.size();
    cout << "Insertion Sort Steps (Integers):\n";
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        // Function 2: Print array after each insertion
        cout << "Step " << i << ": ";
        for (int k = 0; k < n; k++)
            cout << arr[k] << " ";
        cout << endl;
    }
}

// Function 3: Insertion Sort for strings (alphabetical order)
void insertionSortString(vector<string> &arr) {
    int n = arr.size();
    cout << "\nInsertion Sort Steps (Strings):\n";
    for (int i = 1; i < n; i++) {
        string key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        cout << "Step " << i << ": ";
        for (int k = 0; k < n; k++)
            cout << arr[k] << " ";
        cout << endl;
    }
}

int main() {
    // Integer array
    vector<int> intArr = {9, 5, 1, 4, 3};
    insertionSortInt(intArr);

    cout << "\nFinal Sorted Integers: ";
    for (int x : intArr)
        cout << x << " ";
    cout << endl;

    // String array
    vector<string> strArr = {"banana", "apple", "cherry", "mango"};
    insertionSortString(strArr);

    cout << "\nFinal Sorted Strings: ";
    for (string s : strArr)
        cout << s << " ";
    cout << endl;

    return 0;
}

/*

Time Complexity:

Best Case: O(n) → Array is already sorted (only comparisons, no shifts)
Average Case: O(n²) → Random order array
Worst Case: O(n²) → Reverse sorted array (maximum shifts)

Space Complexity:
Auxiliary Space: O(1) → In-place sorting, no extra array needed

*/