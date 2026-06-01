
/* ================================================================================
Solution 1:

Insert into a Binary Search Tree:
    1. If the tree is empty, return a new node with the given value.
    2. Otherwise, compare the given value with the value of the current node:
    a. If the given value is less than the current node's value, recursively insert the value into the left subtree.
    b. If the given value is greater than the current node's value, recursively insert the value into the right subtree.
    3. Return the unchanged node pointer (the root of the tree).

Time Complexity: O(h), where h is the height of the tree. In the worst case (when the tree is skewed), this can be O(n), where n is the number of nodes in the tree. In the average case (when the tree is balanced), this is O(log n).
Space Complexity: O(h) due to the recursive call stack. In the worst case (when the tree is skewed), this can be O(n). In the average case (when the tree is balanced), this is O(log n).
*/