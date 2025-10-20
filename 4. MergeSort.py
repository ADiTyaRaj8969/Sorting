"""
Merge Sort Implementation in Python

This script demonstrates the recursive Merge Sort algorithm. It's a classic
divide-and-conquer algorithm known for its stable performance.
"""

def print_subarray(arr, start, end):
    """Helper function to print a slice of a list."""
    # Slicing creates the subarray, map converts numbers to strings, join combines them.
    sub = ' '.join(map(str, arr[start:end + 1]))
    print(f"[ {sub} ]", end="")

def merge(arr, left, mid, right):
    """Merges two sorted subarrays into a single sorted subarray."""
    print("\nMerging...")
    print("Left: ", end="")
    print_subarray(arr, left, mid)
    print(" | Right: ", end="")
    print_subarray(arr, mid + 1, right)
    print() # Newline

    # Create temporary lists for the left and right halves using slicing
    left_half = arr[left : mid + 1]
    right_half = arr[mid + 1 : right + 1]

    i = 0  # Initial index for the left half
    j = 0  # Initial index for the right half
    k = left # Initial index for the merged subarray

    # --- The Merge Process ---
    # Compare elements from both halves and copy the smaller one
    while i < len(left_half) and j < len(right_half):
        if left_half[i] <= right_half[j]:
            arr[k] = left_half[i]
            i += 1
        else:
            arr[k] = right_half[j]
            j += 1
        k += 1

    # --- Copy any remaining elements ---
    # If the left half has elements left
    while i < len(left_half):
        arr[k] = left_half[i]
        i += 1
        k += 1

    # If the right half has elements left
    while j < len(right_half):
        arr[k] = right_half[j]
        j += 1
        k += 1
        
    print("Merged (Sorted Subarray): ", end="")
    print_subarray(arr, left, right)
    print("\n" + "-"*30) # Separator for clarity

def merge_sort(arr, left, right):
    """
    The main recursive function that sorts arr[left..right] using Merge Sort.
    """
    if left < right:
        # Find the middle point to divide the array into two halves
        mid = (left + right) // 2

        # Recursively sort the first and second halves
        merge_sort(arr, left, mid)
        merge_sort(arr, mid + 1, right)

        # Merge the two sorted halves
        merge(arr, left, mid, right)

def main():
    """Main function to test the merge_sort."""
    arr = [38, 27, 43, 3, 9, 82, 10]
    
    print(f"Original Array: {' '.join(map(str, arr))}")
    print("-" * 30)
    
    merge_sort(arr, 0, len(arr) - 1)
    
    print("\nFinal Sorted Array: ", ' '.join(map(str, arr)))

if __name__ == "__main__":
    main()
    """
    Time Complexity:
    - Best Case: O(n log n)
    - Average Case: O(n log n)
    - Worst Case: O(n log n)

    Space Complexity:
    - Auxiliary Space: O(n) -> Requires extra space for temporary arrays during merging.
    
    """