def heapify(arr, n, i):
    """
    To heapify a subtree rooted at index i.
    n is the size of the heap.
    """
    largest = i      # Initialize largest as root
    left = 2 * i + 1   # Left child
    right = 2 * i + 2  # Right child

    # See if left child of root exists and is greater than root
    if left < n and arr[left] > arr[largest]:
        largest = left

    # See if right child of root exists and is greater than root
    if right < n and arr[right] > arr[largest]:
        largest = right

    # Change root, if needed
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  # Swap
        # Heapify the root of the affected sub-tree
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)

    # Step 1: Build a max-heap from the input array.
    # We start from the last non-leaf node and move up.
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    
    print(f"Max-Heap: {' '.join(map(str, arr))}")

    # Step 2: One by one extract elements from the heap.
    for i in range(n - 1, 0, -1):
        # Move the current root (max element) to the end of the array
        arr[i], arr[0] = arr[0], arr[i]
        
        # Call max heapify on the reduced heap
        heapify(arr, i, 0)
        
        print(f"After moving max to position {i}: {' '.join(map(str, arr))}")

def main():
    """Main function to test the heap_sort."""
    arr = [12, 11, 13, 5, 6, 7]
    
    print(f"Original array: {' '.join(map(str, arr))}")
    
    heap_sort(arr)
    
    print(f"Sorted array: {' '.join(map(str, arr))}")

if __name__ == "__main__":
    main()
"""
    Sorts a list in place using the Heap Sort algorithm.

    Type: Comparison-based, Not stable, In-place

    Time Complexity:
    - Best Case: O(n log n)
    - Average Case: O(n log n)
    - Worst Case: O(n log n)

    Space Complexity:
    - Auxiliary Space: O(1)
    """