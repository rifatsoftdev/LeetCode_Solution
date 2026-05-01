# 108_Convert_Sorted_Array_to_Binary_Search_Tree

```
Convert Sorted Array to Binary Search Tree:
    1. To create a height-balanced BST from a sorted array, the middle element of the array should be the root.
    2. Recursively apply the same logic to the left half of the array to build the left subtree.
    3. Recursively apply the same logic to the right half of the array to build the right subtree.
    4. The base case for the recursion is when the left index exceeds the right index, returning null.

Time Complexity: O(n), where n is the number of elements in the array, as we visit each element once.
Space Complexity: O(log n) for the recursion stack, as the tree is balanced.
```