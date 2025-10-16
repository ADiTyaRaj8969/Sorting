"""
Bubble Sort Implementations in Python

This script demonstrates three variations of the Bubble Sort algorithm:
1. Basic Bubble Sort: The standard implementation.
2. Optimized Bubble Sort: Stops execution early if the list becomes sorted.
3. Bubble Sort with Swap Count: Counts and displays the total number of swaps.

"""

def bubble_sort_basic(nums):
    """1. Basic Bubble Sort implementation."""
    print("\n--- Basic Bubble Sort ---")
    n = len(nums)
    # Outer loop for passes
    for i in range(n - 1):
        # Inner loop for comparisons and swaps
        for j in range(n - i - 1):
            if nums[j] > nums[j + 1]:
                # Python's concise way to swap elements
                nums[j], nums[j + 1] = nums[j + 1], nums[j]

    # ' '.join(map(str, ...)) is a Pythonic way to print list elements
    print(f"Sorted array: {' '.join(map(str, nums))}")


def bubble_sort_optimized(nums):
    """2. Optimized Bubble Sort that stops early if the list is sorted."""
    print("\n--- Optimized Bubble Sort ---")
    n = len(nums)
    # Outer loop for passes
    for i in range(n - 1):
        swapped = False
        # Inner loop for comparisons and swaps
        for j in range(n - i - 1):
            if nums[j] > nums[j + 1]:
                nums[j], nums[j + 1] = nums[j + 1], nums[j]
                swapped = True
        
        # If no swaps were made in a pass, the array is sorted
        if not swapped:
            print(f"Array became sorted early at pass {i + 1}.")
            break
            
    print(f"Sorted array: {' '.join(map(str, nums))}")


def bubble_sort_count(nums):
    """3. Bubble Sort that counts the number of swaps performed."""
    print("\n--- Bubble Sort with Swap Counter ---")
    n = len(nums)
    swap_count = 0
    # Outer loop for passes
    for i in range(n - 1):
        # Inner loop for comparisons and swaps
        for j in range(n - i - 1):
            if nums[j] > nums[j + 1]:
                nums[j], nums[j + 1] = nums[j + 1], nums[j]
                swap_count += 1

    print(f"Sorted array: {' '.join(map(str, nums))}")
    print(f"Total swaps performed: {swap_count}")


def main():
    """Main function to demonstrate the sorting functions."""
    data = [64, 34, 25, 12, 22, 11, 90]
    
    print(f"Original array: {' '.join(map(str, data))}")
    
    # We pass a copy of the list (`data.copy()`) to each function
    # so that they all start with the same unsorted data.
    bubble_sort_basic(data.copy())
    bubble_sort_optimized(data.copy())
    bubble_sort_count(data.copy())

# Standard entry point for a Python script
if __name__ == "__main__":
    main()
    """
    Time Complexity:
    - Best Case: O(n) -> For the optimized version when the list is already sorted.
    - Average Case: O(n^2) -> For a randomly ordered list.
    - Worst Case: O(n^2) -> For a list sorted in reverse order.

    Space Complexity:
    - Auxiliary Space: O(1) -> It's an in-place sorting algorithm.
    
    """