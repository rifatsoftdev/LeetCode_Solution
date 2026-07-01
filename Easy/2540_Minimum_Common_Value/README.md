# 2540_Minimum_Common_Value

/* ================================================================================
Solution 1:

Optimal Approach (Two Pointers):
    1. Use two pointers to iterate through both sorted arrays simultaneously.
    2. If the elements at both pointers are equal, return that element as the minimum common value.
    3. If the element in the first array is smaller, move the pointer of the first array forward; otherwise, move the pointer of the second array forward.
    4. If no common value is found by the end of the iteration, return -1.

Time Complexity: O(n + m) (where n and m are the lengths of the two arrays)
Space Complexity: O(1)
*/