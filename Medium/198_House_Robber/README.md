# 198_House_Robber

/* ================================================================================
Solution 1:

House Robber (Memoization (Top-Down)):
    1. Use a memoization table to store the results of subproblems and avoid redundant calculations.
    2. For each house, the robber has two choices: rob the current house and move to the house two steps back, or skip the current house and move to the previous house.
    3. The recursive relation is: `rob(i) = max(nums[i] + rob(i - 2), rob(i - 1))`.
    4. Base cases: if the index is less than 0, return 0.

Time Complexity: O(n)
Space Complexity: O(n)

*/