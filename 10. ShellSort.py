def shell_sort(arr):
    n = len(arr)
    
    # Start with a big gap, then reduce the gap
    gap = n // 2
    while gap > 0:
        # Perform a gapped insertion sort for this gap size.
        # The first gap elements arr[0..gap-1] are already in gapped order
        # so we can start the loop from gap.
        for i in range(gap, n):
            # Save arr[i] in temp and make a hole at position i
            temp = arr[i]
            
            # Shift earlier gap-sorted elements up until the correct location
            # for arr[i] is found
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            
            # Put temp (the original arr[i]) in its correct location
            arr[j] = temp
            
        print(f"After gap {gap}: {' '.join(map(str, arr))}")
        
        # Reduce the gap for the next iteration
        gap //= 2

def main():
    """Main function to test the shell_sort."""
    arr = [12, 34, 54, 2, 3]

    print(f"Original array: {' '.join(map(str, arr))}")

    shell_sort(arr)

    print(f"Sorted array: {' '.join(map(str, arr))}")

if __name__ == "__main__":
    main()
    """
    Sorts a list in place using the Shell Sort algorithm.

    Type: Comparison-based, Not stable, In-place

    Time Complexity (Worst Case):
    Depends on the gap sequence used.
    - Original Shell’s sequence (n/2, n/4, ...): O(n^2)
    - Better sequences (e.g., Sedgewick): Can reach O(n^(4/3))
    - Best Case: O(n log n)

    Space Complexity:
    - Auxiliary Space: O(1) -> In-place sorting
    """