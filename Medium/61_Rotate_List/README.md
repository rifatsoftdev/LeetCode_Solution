# 61_Rotate_List


Rotate List:
    1. Calculate the length of the linked list and find the last node.
    2. Connect the last node to the head to make it a circular list.
    3. The new head will be at position `(length - k % length)`.
    4. Traverse to the node just before the new head, break the circular connection by setting its next to null, and return the new head.

Time Complexity: O(n), where n is the number of nodes in the list.
Space Complexity: O(1), as we only use a few pointers.