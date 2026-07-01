from typing import List, Optional
from devlibs.singly_linkedlist import ListNode, listToSinglyLinkedList, printSinglyLinkList


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head or not head.next:
            return

        # Step 1: Find the middle of the linked list
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # Step 2: Reverse the second half of the list
        second = slow.next
        prev = slow.next = None
        while second:
            tmp = second.next
            second.next = prev
            prev = second
            second = tmp

        # Step 3: Merge the two halves
        first, second = head, prev
        while second:
            tmp1, tmp2 = first.next, second.next
            first.next = second
            second.next = tmp1
            first, second = tmp1, tmp2
        


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    head1 = listToSinglyLinkedList([1, 2, 3, 4])
    solution.reorderList(head1)
    printSinglyLinkList(head1)

    # test cases 2
    head2 = listToSinglyLinkedList([1, 2, 3, 4, 5])
    solution.reorderList(head2)
    printSinglyLinkList(head2)
    
    