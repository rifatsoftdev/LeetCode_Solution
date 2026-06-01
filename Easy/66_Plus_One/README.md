[Array]

# 66. Plus One

Description
- Given a non-empty array of decimal digits representing a non-negative integer, add one to the integer.
- The most significant digit is at the head of the list and each element contains a single digit.

Examples
- Example 1: Input: [1, 2, 3]  → Output: [1, 2, 4]
- Example 2: Input: [4, 3, 2, 1] → Output: [4, 3, 2, 2]
- Example 3: Input: [9]         → Output: [1, 0]

Constraints
- 1 <= digits.length <= 100
- 0 <= digits[i] <= 9
- The array does not contain leading zeros except for the number 0 itself

Approach
1. Traverse the digits from right (least significant) to left.
2. Add one to the current digit.
   - If the result is <= 9, update the digit and return the array.
   - If the result is 10, set the current digit to 0 and carry the 1 to the next digit on the left.
3. If you exit the loop with a remaining carry (all digits were 9), insert 1 at the beginning of the array.

Pseudocode
```
for i from n-1 downto 0:
    digits[i] += 1
    if digits[i] < 10:
        return digits
    digits[i] = 0
insert 1 at front
return digits
```

Complexity
- Time: O(n) — single pass from right to left
- Space: O(1) extra space (O(n) if a new leading digit is inserted)

Notes
- Works for very large integers represented as digit arrays where integer overflow would occur.

Reference
- LeetCode Problem 66: Plus One
