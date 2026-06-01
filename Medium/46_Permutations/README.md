# 46_Permutations

/* ================================================================================
Solution 1:

Optimal solution (Backtracking):
    1. We can use backtracking to generate all possible permutations of the input array.
    2. We define a recursive function that takes the current index and the input array. If the current index is equal to the size of the array, we add the current permutation to the result.
    3. We iterate through the array starting from the current index, swapping the current index with the iterating index and recursively calling the function with the next index.
    4. After the recursive call, we swap back to restore the original array for the next iteration.

Time complexity: O(n*n!)
Space complexity: O(n*n!)
*/