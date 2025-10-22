def counting_sort_by_digit(arr, exp):
    """
    Performs a stable sort on the array based on the digit at the
    given exponent place (exp). This is a subroutine for Radix Sort.
    """
    n = len(arr)
    # The output array that will have sorted numbers
    output = [0] * n
    # Initialize count array for digits 0-9
    count = [0] * 10

    # 1. Store the count of occurrences of each digit
    for i in range(n):
        index = (arr[i] // exp) % 10
        count[index] += 1

    # 2. Change count[i] so that count[i] now contains the actual
    #    position of this digit in the output array
    for i in range(1, 10):
        count[i] += count[i - 1]

    # 3. Build the output array. We iterate from the end to make it stable.
    i = n - 1
    while i >= 0:
        index = (arr[i] // exp) % 10
        output[count[index] - 1] = arr[i]
        count[index] -= 1
        i -= 1

    # 4. Copy the output array to arr[], so that arr now contains
    #    the sorted numbers according to the current digit.
    for i in range(n):
        arr[i] = output[i]
        
    print(f"After sorting by 10^{len(str(exp))-1}s place: {' '.join(map(str, arr))}")

def radix_sort(arr):
    # Find the maximum number to know the number of digits
    if not arr:
        return
    max_val = max(arr)

    # Do counting sort for every digit. Note that instead of passing the
    # digit number, exp is passed. exp is 10^i where i is current digit number.
    exp = 1
    while max_val // exp > 0:
        counting_sort_by_digit(arr, exp)
        exp *= 10

def main():
    """Main function to test the radix_sort."""
    arr = [170, 45, 75, 90, 802, 24, 2, 66]
    
    print(f"Original array: {' '.join(map(str, arr))}")
    print("-" * 30)
    
    radix_sort(arr)
    
    print("-" * 30)
    print(f"Sorted array: {' '.join(map(str, arr))}")

if __name__ == "__main__":
    main()
    """
    Sorts a list in place using the Radix Sort algorithm.

    Type: Non-comparison-based, Stable

    Time Complexity:
    - Best, Average, Worst Case: O(d * (n + b)) where d is the number of digits
      in the max number, n is the size of the list, and b is the base (10).
      Simplified to O(nk) where k is the number of digits.

    Space Complexity:
    - Auxiliary Space: O(n + k) -> For the counting sort subroutine.
    """