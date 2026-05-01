## 2566_Maximum_Difference_by_Remapping_a_Digit

Maximum Difference by Remapping a Digit:
    1. You are given an integer num. You will apply the following steps exactly two times:
        1. Pick a digit x (0 <= x <= 9).
        2. Pick another digit y (0 <= y <= 9). The digit y can be equal to x.
        3. Replace all the occurrences of x in num by y, and add the new integer obtained to a set.
    2. Return the maximum difference between any two integers in the set.

Time Complexity: O(n) where n is the number of digits in num.
Space Complexity: O(n) where n is the number of digits in num.