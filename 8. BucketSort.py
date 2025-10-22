def bucket_sort(arr):
    """
    Sorts a list of floats in the range [0, 1) using Bucket Sort.

    Type: Non-comparison-based, Stable

    Time Complexity:
    - Best Case: O(n + k) -> When elements are uniformly distributed.
    - Average Case: O(n + k) -> n = elements, k = buckets.
    - Worst Case: O(n^2) -> When all elements fall into one bucket.

    Space Complexity:
    - Auxiliary Space: O(n + k) -> For the buckets.
    """
    n = len(arr)
    # 1. Create n empty buckets
    buckets = [[] for _ in range(n)]

    # 2. Distribute array elements into different buckets
    for num in arr:
        # Calculate bucket index. Multiplying by n maps the float
        # to an index in the range [0, n-1].
        index = int(n * num)
        buckets[index].append(num)

    # Display buckets before sorting them individually
    print("Buckets before sorting:")
    for i, bucket in enumerate(buckets):
        # Using a generator expression with ' '.join for cleaner printing
        bucket_content = ' '.join(map(str, bucket))
        print(f"Bucket {i}: {bucket_content}")

    # 3. Sort individual buckets
    for bucket in buckets:
        bucket.sort() # Python's Timsort is used here

    # Display buckets after sorting
    print("\nBuckets after sorting:")
    for i, bucket in enumerate(buckets):
        bucket_content = ' '.join(map(str, bucket))
        print(f"Bucket {i}: {bucket_content}")
    
    # 4. Concatenate all buckets back into arr
    idx = 0
    for bucket in buckets:
        for num in bucket:
            arr[idx] = num
            idx += 1

def main():
    """Main function to test the bucket_sort."""
    arr = [0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68]
    
    print(f"Original array: {' '.join(map(str, arr))}\n")
    
    bucket_sort(arr)
    
    print(f"\nSorted array: {' '.join(map(str, arr))}")

if __name__ == "__main__":
    main()
    """
    Sorts a list of floats in the range [0, 1) using Bucket Sort.

    Type: Non-comparison-based, Stable

    Time Complexity:
    - Best Case: O(n + k) -> When elements are uniformly distributed.
    - Average Case: O(n + k) -> n = elements, k = buckets.
    - Worst Case: O(n^2) -> When all elements fall into one bucket.

    Space Complexity:
    - Auxiliary Space: O(n + k) -> For the buckets.
    """