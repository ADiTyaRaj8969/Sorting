def comb_sort(arr):
    n = len(arr)
    gap = n
    shrink = 1.3
    sorted = False

    while not sorted:
        # Update the gap value
        gap = int(gap / shrink)
        if gap <= 1:
            gap = 1
            sorted = True  # Assume the array is sorted

        # Compare elements with the current gap
        for i in range(n - gap):
            if arr[i] > arr[i + gap]:
                # Swap elements
                arr[i], arr[i + gap] = arr[i + gap], arr[i]
                sorted = False  # If a swap happens, the array is not sorted yet

        print(f"Array after gap {gap}: {' '.join(map(str, arr))}")

def main():
    """Main function to test the comb_sort."""
    arr = [8, 4, 1, 56, 3, -44, 23, -6, 28, 0]
    
    print("Original array: ", ' '.join(map(str, arr)))
    
    comb_sort(arr)
    
    print("Sorted array (Comb Sort): ", ' '.join(map(str, arr)))

if __name__ == "__main__":
    main()
    """
    Sorts a list in place using the Comb Sort algorithm.

    Type: Comparison-based, Not stable, In-place

    Time Complexity:
    Best Case: O(n log n) -> When the array is nearly sorted
    Average Case: O(n^2 / 2^p) where p is the number of increments. Roughly O(n log n).
    Worst Case: O(n^2) -> Though rare with the 1.3 shrink factor.

    Space Complexity:
    Auxiliary Space: O(1) -> In-place sorting
    """
    