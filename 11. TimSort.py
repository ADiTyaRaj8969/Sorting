# The size of the chunks to be sorted initially by insertion sort.
# A value between 32 and 64 is typical.
RUN = 32

def insertion_sort(arr, left, right):
    """
    Sorts a slice of an array using insertion sort.
    This is efficient for small arrays.
    """
    for i in range(left + 1, right + 1):
        temp = arr[i]
        j = i - 1
        # Move elements of arr[0..i-1], that are greater than temp,
        # to one position ahead of their current position
        while j >= left and arr[j] > temp:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = temp

def merge(arr, l, m, r):
    """
    Merges two sorted subarrays arr[l..m] and arr[m+1..r].
    """
    # Create temporary arrays from the slices
    left = arr[l : m + 1]
    right = arr[m + 1 : r + 1]

    i, j, k = 0, 0, l

    # Copy data to temp arrays left[] and right[]
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1
        k += 1

    # Check if any element was left in the left subarray
    while i < len(left):
        arr[k] = left[i]
        k += 1
        i += 1

    # Check if any element was left in the right subarray
    while j < len(right):
        arr[k] = right[j]
        k += 1
        j += 1

def tim_sort(arr):
    
    n = len(arr)
    
    # Step 1: Sort individual subarrays of size RUN using insertion sort
    for i in range(0, n, RUN):
        end = min(i + RUN - 1, n - 1)
        insertion_sort(arr, i, end)

    # Step 2: Start merging from size RUN. It will merge to form size 2*RUN,
    # then 4*RUN, 8*RUN, and so on.
    size = RUN
    while size < n:
        # Pick starting point of left sub array. We're going to merge
        # arr[left..left+size-1] and arr[left+size..left+2*size-1]
        for left in range(0, n, 2 * size):
            # Find ending point of left sub array
            mid = min(left + size - 1, n - 1)
            # Find ending point of right sub array
            right = min(left + 2 * size - 1, n - 1)

            # Merge the two subarrays if the right one exists
            if mid < right:
                merge(arr, left, mid, right)
        
        size *= 2
        
    print(f"Sorted array (Tim Sort): {' '.join(map(str, arr))}")


def main():
    """Main function to test the tim_sort."""
    arr = [5, 21, 7, 23, 19, 2, 1, 15]
    
    print(f"Original array: {' '.join(map(str, arr))}")
    
    tim_sort(arr)

if __name__ == "__main__":
    main()

    
    """
    Sorts a list in place using the Tim Sort algorithm.

    Type: Comparison-based, Stable
    Time Complexity:
    - Best Case: O(n)
    - Average Case: O(n log n)
    - Worst Case: O(n log n)
    Space Complexity:
    - Auxiliary Space: O(n) in this implementation (can be O(k) for k runs)
    Characteristics:
    A hybrid stable sorting algorithm, derived from merge sort and insertion sort.
    It's the default sorting algorithm used in Python.
    """