"""
Quick Sort Implementations in Python

This script demonstrates three variations of the Quick Sort algorithm:
1. Using the first element as the pivot.
2. Using the last element as the pivot (Lomuto partition scheme).
3. Using the median-of-three as the pivot to improve performance.
"""

# Global counters for recursive calls
count_first = 0
count_last = 0
count_median = 0

def print_array(arr):
    """Helper function to print the contents of a list."""
    print(' '.join(map(str, arr)))

# --- 1. Quick Sort: First Element as Pivot (Hoare-like partition) ---

def partition_first(arr, low, high):
    pivot = arr[low]
    i = low + 1
    j = high
    while True:
        # Find element on the left that should be on the right
        while i <= high and arr[i] <= pivot:
            i += 1
        # Find element on the right that should be on the left
        while arr[j] > pivot:
            j -= 1
        # Swap elements, or break if pointers cross
        if i >= j:
            break
        arr[i], arr[j] = arr[j], arr[i]
    # Place pivot in its correct position
    arr[low], arr[j] = arr[j], arr[low]
    print(f"Pivot(First={pivot}): ", end="")
    print_array(arr)
    return j

def quick_sort_first(arr, low, high):
    global count_first
    count_first += 1
    if low < high:
        pi = partition_first(arr, low, high)
        quick_sort_first(arr, low, pi - 1)
        quick_sort_first(arr, pi + 1, high)

# --- 2. Quick Sort: Last Element as Pivot (Lomuto partition) ---

def partition_last(arr, low, high):
    pivot = arr[high]
    i = low - 1  # Index of smaller element
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    # Place pivot in its correct position
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    print(f"Pivot(Last={pivot}): ", end="")
    print_array(arr)
    return i + 1

def quick_sort_last(arr, low, high):
    global count_last
    count_last += 1
    if low < high:
        pi = partition_last(arr, low, high)
        quick_sort_last(arr, low, pi - 1)
        quick_sort_last(arr, pi + 1, high)

# --- 3. Quick Sort: Median-of-Three Pivot ---

def median_of_three(arr, low, high):
    mid = (low + high) // 2
    # Sort low, mid, and high elements to find the median
    if arr[mid] < arr[low]:
        arr[mid], arr[low] = arr[low], arr[mid]
    if arr[high] < arr[low]:
        arr[high], arr[low] = arr[low], arr[high]
    if arr[mid] > arr[high]:
        arr[mid], arr[high] = arr[high], arr[mid]
    
    # Place the median at the 'low' index to be used as the pivot
    arr[low], arr[mid] = arr[mid], arr[low]
    return arr[low]

def partition_median(arr, low, high):
    pivot = median_of_three(arr, low, high)
    # The partitioning logic is the same as the first_element version
    i = low + 1
    j = high
    while True:
        while i <= high and arr[i] <= pivot:
            i += 1
        while arr[j] > pivot:
            j -= 1
        if i >= j:
            break
        arr[i], arr[j] = arr[j], arr[i]
    arr[low], arr[j] = arr[j], arr[low]
    print(f"Pivot(Median={pivot}): ", end="")
    print_array(arr)
    return j

def quick_sort_median(arr, low, high):
    global count_median
    count_median += 1
    if low < high:
        pi = partition_median(arr, low, high)
        quick_sort_median(arr, low, pi - 1)
        quick_sort_median(arr, pi + 1, high)

# --- Main execution ---
def main():
    arr = [29, 10, 14, 37, 13, 25, 3, 8]

    # Create copies for each sort version
    a1, a2, a3 = list(arr), list(arr), list(arr)
    
    print("Original: ", end="")
    print_array(arr)

    print("\n-- First Element Pivot --")
    quick_sort_first(a1, 0, len(a1) - 1)
    print("Sorted: ", end="")
    print_array(a1)
    print(f"Calls: {count_first}")

    print("\n-- Last Element Pivot --")
    quick_sort_last(a2, 0, len(a2) - 1)
    print("Sorted: ", end="")
    print_array(a2)
    print(f"Calls: {count_last}")

    print("\n-- Median-of-Three Pivot --")
    quick_sort_median(a3, 0, len(a3) - 1)
    print("Sorted: ", end="")
    print_array(a3)
    print(f"Calls: {count_median}")

if __name__ == "__main__":
    main()

    """
    Time Complexity:
    - Best Case: O(n log n) -> Pivot consistently divides the array into balanced halves.
    - Average Case: O(n log n) -> For randomly ordered inputs.
    - Worst Case: O(n^2) -> Pivot is always the min/max element (e.g., a sorted array).

    Space Complexity:
    - Auxiliary Space: O(log n) -> Due to the recursive call stack (for in-place sort). 
   """