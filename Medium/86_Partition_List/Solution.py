from typing import List, Optional
from devlibs.singly_linkedlist import ListNode, printSinglyLinkList


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        smaller = ListNode(0)
        larger = ListNode(0)

        smaller_head = smaller
        larger_head = larger

        while head:
            if head.val < x:
                smaller.next = head
                smaller = smaller.next
            else:
                larger.next = head
                larger = larger.next

            head = head.next

        larger.next = None
        smaller.next = larger_head.next

        return smaller_head.next


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    head = ListNode(1, ListNode(4, ListNode(3, ListNode(2, ListNode(5, ListNode(2))))))
    x = 3
    result1 = solution.partition(head, x)
    printSinglyLinkList(result1)  # Expected output: [1, 2, 2, 4, 3, 5]

    # test cases 2
    head2 = ListNode(2, ListNode(1))
    x2 = 2
    result2 = solution.partition(head2, x2)
    printSinglyLinkList(result2)  # Expected output: [1, 2]