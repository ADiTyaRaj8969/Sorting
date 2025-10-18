"""
Insertion Sort Implementation in Python

This script provides a function to perform Insertion Sort on a list.
It works for any list whose elements can be compared (e.g., numbers, strings).

"""

def insertion_sort(arr, data_type="items"):
    """
    Sorts a list in-place using the Insertion Sort algorithm.
    Prints the state of the list after each main step.

    Args:
        arr: The list to be sorted.
        data_type: A string describing the type of data for print statements.
    """
    print(f"\nInsertion Sort Steps ({data_type}):")
    # Start from the second element (index 1) as the first is considered sorted.
    for i in range(1, len(arr)):
        # The element to be inserted into the sorted portion
        key = arr[i]
        
        # Start comparing with the element just before the key
        j = i - 1

        # Move elements of the sorted portion (arr[0..i-1]) that are greater
        # than the key one position to their right.
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        
        # Place the key at its correct sorted position
        arr[j + 1] = key

        # Print the list after the key has been inserted
        # ' '.join(map(str, arr)) is a Pythonic way to print list elements
        print(f"Step {i}: {' '.join(map(str, arr))}")

def main():
    """Main function to demonstrate insertion_sort."""
    
    # --- 1. Sort an array of integers ---
    int_arr = [9, 5, 1, 4, 3]
    print(f"Original Integers: {' '.join(map(str, int_arr))}")
    insertion_sort(int_arr, data_type="Integers")
    print(f"\nFinal Sorted Integers: {' '.join(map(str, int_arr))}")

    print("\n" + "="*40 + "\n") # Separator

    # --- 2. Sort an array of strings alphabetically ---
    str_arr = ["banana", "apple", "cherry", "mango", "date"]
    print(f"Original Strings: {' '.join(str_arr)}")
    insertion_sort(str_arr, data_type="Strings")
    print(f"\nFinal Sorted Strings: {' '.join(str_arr)}")

if __name__ == "__main__":
    main()
    
    """
    Time Complexity:
    - Best Case: O(n) -> The list is already sorted. The inner loop never runs.
    - Average Case: O(n^2) -> For a randomly ordered list.
    - Worst Case: O(n^2) -> The list is sorted in reverse order.

    Space Complexity:
    - Auxiliary Space: O(1) -> It's an in-place sorting algorithm.

    """