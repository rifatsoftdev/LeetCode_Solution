# 69_Sqrt_x

Searching Algorithm: Binary Search
    1. If x is 0 or 1, return x (since the square root of 0 is 0 and the square root of 1 is 1).
    2. Initialize two pointers, start and end, to 0 and x/2, respectively (the square root of x cannot be greater than x/2 for x > 1).
    3. While start is less than or equal to end:
        a. Calculate the middle index (mid) as the average of start and end.
        b. If mid * mid is equal to x, return mid (the square root is found).
        c. If mid * mid is less than x, update ans to mid and move the start pointer to mid + 1 (search in the right half).
        d. If mid * mid is greater than x, move the end pointer to mid - 1 (search in the left half).
    4. If the loop ends without finding an exact square root, return ans, which holds the largest integer whose square is less than or equal to x.

Time Complexity: O(log x)
Space Complexity: O(1)