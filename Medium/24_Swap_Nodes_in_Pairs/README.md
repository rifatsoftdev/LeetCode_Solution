# 24_Swap_Nodes_in_Pairs


/* ================================================================================
Solution 1:

Swap Nodes in Pairs (Iterative Value Swap):
    1. Traverse the linked list using a pointer `temp`, starting from the `head`.
    2. In each step, check if the current node and the next node exist.
    3. If both exist, swap their values.
    4. Move the pointer `temp` two steps forward to the next pair.
    5. Continue until the end of the list is reached.

Time Complexity: O(n), where n is the number of nodes in the linked list.
Space Complexity: O(1), as we only swap values in-place without using extra nodes.
*/