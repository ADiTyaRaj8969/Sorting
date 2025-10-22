def counting_sort(arr):
    if not arr:
        return

    # --- Step 1: Find the maximum element to determine the range ---
    max_val = max(arr)

    # --- Step 2: Create the count array ---
    # Stores the frequency of each element.
    count = [0] * (max_val + 1)
    for num in arr:
        count[num] += 1
        
    print(f"Count array: {' '.join(map(str, count))}")

    # --- Step 3: Create the cumulative frequency array ---
    # Stores the count of elements less than or equal to the index.
    # This determines the final position of elements in the sorted array.
    cum_freq = list(count)
    for i in range(1, len(cum_freq)):
        cum_freq[i] += cum_freq[i - 1]

    print(f"Cumulative frequency array: {' '.join(map(str, cum_freq))}")

    # --- Step 4: Build the sorted array ---
    # Iterate from the end of the original array to maintain stability.
    sorted_arr = [0] * len(arr)
    for i in range(len(arr) - 1, -1, -1):
        num = arr[i]
        # Get the correct position from the cumulative frequency array
        position = cum_freq[num] - 1
        sorted_arr[position] = num
        # Decrement the count for the next occurrence of this number
        cum_freq[num] -= 1

    # --- Step 5: Copy the sorted array back to the original ---
    # This modifies the list in-place for the caller.
    arr[:] = sorted_arr

def main():
    """Main function to test the counting_sort."""
    arr = [4, 2, 2, 8, 3, 3, 1]
    
    print(f"Original array: {' '.join(map(str, arr))}")
    print("-" * 30)
    
    counting_sort(arr)
    
    print("-" * 30)
    print(f"Sorted array: {' '.join(map(str, arr))}")

if __name__ == "__main__":
    main()
    """
    Sorts a list of non-negative integers in place using Counting Sort.

    Type: Non-comparison-based, Stable

    Time Complexity:
    - Best, Average, Worst: O(n + k) where n is the number of elements
      and k is the range of the input values (max_val).

    Space Complexity:
    - Auxiliary Space: O(k) for the count/cumulative array.
    """