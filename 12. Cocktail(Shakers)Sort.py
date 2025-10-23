def cocktail_sort(arr):
    swapped = True
    start = 0
    end = len(arr) - 1

    while swapped:
        # Reset the swapped flag before each full pass
        swapped = False

        # Forward pass (like bubble sort)
        # Moves the largest element to its correct position
        for i in range(start, end):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]  # Swap
                swapped = True

        # If nothing moved, then the array is sorted.
        if not swapped:
            break

        # Otherwise, reset the flag for the backward pass
        swapped = False

        # The last element is now in its correct place
        end -= 1

        # Backward pass
        # Moves the smallest element to its correct position
        for i in range(end - 1, start - 1, -1):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]  # Swap
                swapped = True

        # The first element is now in its correct place
        start += 1
        
        print(f"Array after pass: {' '.join(map(str, arr))}")

def main():
    """Main function to test the cocktail_sort."""
    arr = [5, 1, 4, 2, 8, 0, 2]
    
    print(f"Original array: {' '.join(map(str, arr))}")
    
    cocktail_sort(arr)
    
    print(f"Sorted array (Cocktail Sort): {' '.join(map(str, arr))}")

# Standard entry point for a Python script
if __name__ == "__main__":
    main()
    """
    Sorts a list in place using the Cocktail Shaker Sort algorithm.

    Type: Comparison-based, Stable, In-place

    Time Complexity:
    - Best Case: O(n) -> When the array is already sorted.
    - Average Case: O(n^2) -> For a randomly ordered array.
    - Worst Case: O(n^2) -> When the array is sorted in reverse.

    Space Complexity:
    - Auxiliary Space: O(1) -> It's an in-place sorting algorithm.

    Characteristics:
    A bidirectional variation of Bubble Sort that sorts in both directions
    on each pass. Also known as Shaker Sort.
    """