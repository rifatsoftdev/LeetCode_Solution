# 704_Binary_Search

/* ================================================================================
Solution 1:

Searching Algorithm: Binary Search
    1. Initialize two pointers, left and right, to the beginning and end of the array, respectively.
    2. While the left pointer is less than or equal to the right pointer:
        a. Calculate the middle index (mid) as the average of left and right.
        b. If the element at mid is equal to the target, return mid (target found).
        c. If the element at mid is less than the target, move the left pointer to mid + 1 (search in the right half).
        d. If the element at mid is greater than the target, move the right pointer to mid - 1 (search in the left half).
    3. If the loop ends without finding the target, return -1 (target not found).

Time Complexity: O(log n)
Space Complexity: O(1)
*/