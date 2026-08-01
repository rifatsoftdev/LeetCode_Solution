from typing import List, Optional
from devlibs.singly_linkedlist import ListNode, listToSinglyLinkedList, printSinglyLinkList


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = head
        new_head = ListNode(0)
        new_curr = new_head

        sum = 0

        while curr:
            if curr.val == 0:
                if sum > 0:
                    new_curr.next = ListNode(sum)
                    new_curr = new_curr.next
                    sum = 0
            else:
                sum += curr.val
            curr = curr.next

        return new_head.next


if __name__ == "__main__":
    solution = Solution()

    # test cases 1
    head1 = listToSinglyLinkedList([0,3,1,0,4,5,2,0])
    result1 = solution.mergeNodes(head1)
    printSinglyLinkList(result1)  # Expected output: 4 -> 11

    # test cases 2
    head2 = listToSinglyLinkedList([0,1,0,3,0,2,2,0])
    result2 = solution.mergeNodes(head2)
    printSinglyLinkList(result2)  # Expected output: 1 -> 3 -> 4

    